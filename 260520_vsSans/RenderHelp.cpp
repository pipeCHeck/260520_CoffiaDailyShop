#include "RenderHelp.h"
#include <wincodec.h>
#include <iostream>

#pragma comment(lib, "windowscodecs.lib")  // WIC 라이브러리
#pragma comment(lib, "msimg32.lib")        // AlphaBlend 함수가 포함된 라이브러리

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

namespace renderHelp
{
    struct WICInitializer
    {
        WICInitializer() = default;

        ~WICInitializer()
        {
        }

        bool Initialize() { // 이니셜라이즈
            m_LastError = CoCreateInstance(
                CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pFactory));

            if (FAILED(m_LastError))
            {
                m_pFactory = nullptr;
                return false;
            }

            return true;
        }

        // 이미지 파일이 정상적으로 로딩되는지 유무 반환
        bool LoadImageFromFile(__in LPCWSTR filename, __out HBITMAP& hBitmap) {
            hBitmap = nullptr;
            if (m_pFactory == nullptr)
            {
                m_LastError = E_FAIL;
                return false;
            }

            m_LastError = m_pFactory->CreateDecoderFromFilename(
                filename, nullptr, GENERIC_READ,
                WICDecodeMetadataCacheOnLoad, &m_pDecoder);

            if (FAILED(m_LastError))
            {
                return false;
            }

            m_LastError = m_pDecoder->GetFrame(0, &m_pFrame);
            if (FAILED(m_LastError))
            {
                return false;
            }

            m_LastError = m_pFactory->CreateFormatConverter(&m_pConverter);
            if (FAILED(m_LastError))
            {
                return false;
            }

            m_LastError = m_pConverter->Initialize(m_pFrame, GUID_WICPixelFormat32bppPBGRA,
                WICBitmapDitherTypeNone, nullptr, 0.0f,
                WICBitmapPaletteTypeCustom);

            if (FAILED(m_LastError))
            {
                return false;
            }

            // 이미지를 로드하는데 필요한 객체들을 생성해 달라고 요청
            // 초기화가 필요한 녀석은 초기화까지

            UINT width = 0, height = 0;
            m_LastError = m_pFrame->GetSize(&width, &height);

            if (FAILED(m_LastError))
            {
                return false;
            }

            BITMAPINFO bmi = { 0 };
            bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
            bmi.bmiHeader.biWidth = width; // 비트맵 너비
            bmi.bmiHeader.biHeight = -static_cast<LONG>(height); // top-down DIB
            bmi.bmiHeader.biPlanes = 1; // 비트맵 평면 수
            bmi.bmiHeader.biBitCount = 32; // 32bpp
            bmi.bmiHeader.biCompression = BI_RGB; // 압축 없음

            void* pvImageBits = nullptr;
            HDC hdc = GetDC(nullptr);
            hBitmap = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, &pvImageBits, nullptr, 0);
            ReleaseDC(nullptr, hdc);

            if (FAILED(m_LastError))
            {
                return false;
            }

            // 비트맵에 픽셀 복사 (32bppPBGRA로 변환)
            m_LastError = m_pConverter->CopyPixels(nullptr, width * 4, width * height * 4, (BYTE*)pvImageBits);

            if (FAILED(m_LastError))
            {
                return false;
            }

            return true;
        }

        HRESULT GetLastError() const
        {
            return m_LastError;
        }

        void Clean()
        {
            if (m_pDecoder) m_pDecoder->Release();
            if (m_pFrame) m_pFrame->Release();
            if (m_pConverter) m_pConverter->Release();
        }

        // 그대로 반환
        BitmapInfo* CreateBitmapInfo(HBITMAP hBitmap)
        {
            BitmapInfo* pNewBitmap = new BitmapInfo(hBitmap);

            return pNewBitmap;
        }

        BitmapInfo* CreateBitmapInfo(HBITMAP hBitmap, int frameCountX, int frameCountY, int frameCount = 1, int offsetX = 0, int offsetY = 0)
        {
            BitmapInfo* pNewBitmap = new BitmapInfo(hBitmap, frameCountX, frameCountY, frameCount, offsetX, offsetY);

            return pNewBitmap;
        }

        HRESULT m_LastError = S_OK;

        IWICImagingFactory* m_pFactory = nullptr;
        IWICBitmapDecoder* m_pDecoder = nullptr;
        IWICBitmapFrameDecode* m_pFrame = nullptr;
        IWICFormatConverter* m_pConverter = nullptr;

        // WICInitializer는 복사할 수 없도록 삭제합니다.
        WICInitializer(const WICInitializer&) = delete;
        WICInitializer& operator=(const WICInitializer&) = delete;
    }GWICInitializer;

    // 바로위 GWICInitializer;는 WICInitializer aaa; 랑 똑같은거임

    void BitmapInfo::SetCurFrame(int index) {
        if (index > frameCount) {
            index %= frameCount;
        }
        curFrame = index;
    }

    BitmapInfo* CreateBitmapInfo(LPCWSTR filename)
    {
        bool bCoInit = GWICInitializer.Initialize();
        if (false == bCoInit)
        {
            return nullptr;
        }

        HBITMAP hBitmap = nullptr;
        BitmapInfo* pBitmapInfo = nullptr;
        if (GWICInitializer.LoadImageFromFile(filename, hBitmap))
        {
            pBitmapInfo = GWICInitializer.CreateBitmapInfo(hBitmap);
        }

        GWICInitializer.Clean();

        return pBitmapInfo;
    }

    BitmapInfo* CreateBitmapInfo(LPCWSTR filename, int frameCountX, int frameCountY, int frameCount, int offsetX, int offsetY)
    {
        // 가로 혹은 세로 갯수가 0개일 수는 없음
        bool possible = frameCountX > 0 && frameCountY > 0;
        if (!possible) {
            return nullptr;
        }

        //std::cout << "Debuggggggggggggg" << filename << std::endl;
        static bool bCoInit = GWICInitializer.Initialize();
        if (false == bCoInit)
        {
            return nullptr;
        }

        HBITMAP hBitmap = nullptr;
        BitmapInfo* pBitmapInfo = nullptr;
        if (GWICInitializer.LoadImageFromFile(filename, hBitmap))
        {
            pBitmapInfo = GWICInitializer.CreateBitmapInfo(hBitmap, frameCountX, frameCountY, frameCount, offsetX, offsetY);
        }

        GWICInitializer.Clean();

        return pBitmapInfo;
    }
}