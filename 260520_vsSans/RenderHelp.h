#pragma once
#include "INC_Windows.h"

namespace renderHelp
{
    struct WICInitializer;
    class BitmapInfo
    {
    public:
        HBITMAP GetBitmapHandle() const { return m_hBitmap; }
        
        // 전체 이미지의 크기 반환
        int GetWidth() const { return m_width; }
        int GetHeight() const { return m_height; }

        // 스프라이트 한 칸의 크기 반환
        int GetFrameWidth() const { return m_width / frameCountX; }
        int GetFrameHeight() const { return m_height / frameCountY; }

        // 스프라이트 갯수 반환
        int GetFrameCountX() const { return frameCountX; }
        int GetFrameCountY() const { return frameCountY; }
        int GetFrameCount() const { return frameCount; }

        // 스프라이트의 이미지 오프셋 반환
        int GetOffsetX() const { return offsetX; }
        int GetOffsetY() const { return offsetY; }

        // 현재 사용할 스프라이트 인덱스 반환
        int GetCurFrame() { return curFrame; }
        void SetCurFrame(int index);

    private:
        friend struct WICInitializer;

        BitmapInfo() = default;

        BitmapInfo(HBITMAP hBitmap)
        {
            m_hBitmap = hBitmap;
            BITMAP bitmap;
            GetObject(hBitmap, sizeof(BITMAP), &bitmap);
            m_width = bitmap.bmWidth;
            m_height = bitmap.bmHeight;
        }

        BitmapInfo(HBITMAP hBitmap, int frameCountX, int frameCountY, int frameCount = 1, int offsetX = 0, int offsetY = 0)
        {
            m_hBitmap = hBitmap;
            BITMAP bitmap;
            GetObject(hBitmap, sizeof(BITMAP), &bitmap);
            m_width = bitmap.bmWidth;
            m_height = bitmap.bmHeight;

            this->frameCountX = frameCountX;
            this->frameCountY = frameCountY;
            this->frameCount = frameCount;
            this->offsetX = offsetX;
            this->offsetY = offsetY;
        }

        ~BitmapInfo()
        {
            if (m_hBitmap)
            {
                DeleteObject(m_hBitmap);
                m_hBitmap = nullptr;
            }
        }

    private:
        // 실제 이미지 비트맵
        HBITMAP m_hBitmap = nullptr;

        // 전체 이미지의 크기
        int m_width = 0;
        int m_height = 0;

        // 이미지 속 스프라이트의 갯수
        int frameCountX = 1;
        int frameCountY = 1;
        int frameCount = 1;

        // 이미지 하나의 위치 오프셋
        int offsetX = 0;
        int offsetY = 0;

        // 이미지 z위치값(앞으로 나올지 뒤로 갈지)
        int indexZ = 0;

        // 현재 이미지 프레임 값
        int curFrame = 0;

        BitmapInfo(const BitmapInfo&) = delete;
        BitmapInfo& operator=(const BitmapInfo&) = delete;
    };

    BitmapInfo* CreateBitmapInfo(LPCWSTR filename);
    BitmapInfo* CreateBitmapInfo(LPCWSTR filename, int frameCountX, int frameCountY, int frameCount, int offsetX = 0, int offsetY = 0);
}
