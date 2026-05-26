#pragma once
#include "INC_Windows.h"

namespace renderHelp
{
    struct WICInitializer;
    class BitmapInfo
    {
    public:
        HBITMAP GetBitmapHandle() const { return m_hBitmap; }
        int GetWidth() const { return m_width; }
        int GetHeight() const { return m_height; }

        int GetFrameCountX() const { return frameCountX; }
        int GetFrameCountY() const { return frameCountY; }
        int GetOffsetX() const { return offsetX; }
        int GetOffsetY() const { return offsetY; }

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

        BitmapInfo(HBITMAP hBitmap, int frameCountX, int frameCountY, int offsetX = 0, int offsetY = 0)
        {
            m_hBitmap = hBitmap;
            BITMAP bitmap;
            GetObject(hBitmap, sizeof(BITMAP), &bitmap);
            m_width = bitmap.bmWidth;
            m_height = bitmap.bmHeight;

            this->frameCountX = frameCountX;
            this->frameCountY = frameCountY;
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
        HBITMAP m_hBitmap = nullptr;

        int m_width = 0;
        int m_height = 0;

        int frameCountX = 1;
        int frameCountY = 1;

        int offsetX = 0;
        int offsetY = 0;

        BitmapInfo(const BitmapInfo&) = delete;
        BitmapInfo& operator=(const BitmapInfo&) = delete;
    };

    BitmapInfo* CreateBitmapInfo(LPCWSTR filename);
    BitmapInfo* CreateBitmapInfo(LPCWSTR filename, int frameCountX, int frameCountY, int offsetX = 0, int offsetY = 0);
}
