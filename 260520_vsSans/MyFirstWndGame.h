#pragma once
#include "NzWndBase.h"
#include "Utillity.h"
#include <functional>

// [CHECK] #7  전방 선언을 사용하여 헤더파일의 의존성을 줄임.
class GameTimer;
class GameObjectBase;
class GameObject;

namespace renderHelp
{
    class BitmapInfo;
}

class MyFirstWndGame : public NzWndBase
{
public:
    MyFirstWndGame() = default;
    ~MyFirstWndGame() override = default;

    bool Initialize();
    void Run();
    void Finalize();

    learning::Vector2f Rotate(learning::Vector2f dir, float angleOffset);

#pragma region resource
    using BitmapInfo = renderHelp::BitmapInfo;

    BitmapInfo* m_pPlayerBitmapInfo = nullptr;
    BitmapInfo* m_pEnemyBitmapInfo = nullptr;

    BitmapInfo* m_pSans_Head = nullptr;
    BitmapInfo* m_pSans_Torso = nullptr;
    BitmapInfo* m_pSans_Legs_01 = nullptr;
    BitmapInfo* m_pSans_Legs_02 = nullptr;
    BitmapInfo* m_pSans_Attack_Horizontal = nullptr;
    BitmapInfo* m_pSans_Attack_Vertical = nullptr;
    BitmapInfo* m_pSans_SpeechBubble = nullptr;
    BitmapInfo* m_pGB_Default = nullptr;
    BitmapInfo* m_pBone_Horizontal_01 = nullptr;
    BitmapInfo* m_pBone_Horizontal_02 = nullptr;
    BitmapInfo* m_pBone_Vertical_01 = nullptr;
    BitmapInfo* m_pBone_Vertical_02 = nullptr;
    BitmapInfo* m_pBone_Vertical_03 = nullptr;
    BitmapInfo* m_pBone_Vertical_04 = nullptr;
    BitmapInfo* m_pBone_Dense_Horizontal = nullptr;
    BitmapInfo* m_pBone_Dense_Vertical = nullptr;

    BitmapInfo* m_pPlayer_Heart = nullptr;
    BitmapInfo* m_pPlayer_HeartBroken = nullptr;
    BitmapInfo* m_pPlayer_HeartFragment = nullptr;
    BitmapInfo* m_pUI_ChoiceButton = nullptr;
    BitmapInfo* m_pUI_AttackMiss = nullptr;
    BitmapInfo* m_pUI_AttackDamage = nullptr;
    BitmapInfo* m_pAttack_Background = nullptr;
    BitmapInfo* m_pAttack_Bar = nullptr;
    BitmapInfo* m_pAttack_Slash = nullptr;
    BitmapInfo* m_pUI_Box = nullptr;

    //BitmapInfo* m_p = nullptr;


#pragma endregion

private:
    void Update();
    void Render();

    void OnResize(int width, int height) override;
    void OnClose() override;

    void OnMouseMove(int x, int y);
    void OnLButtonDown(int x, int y);
    void OnRButtonDown(int x, int y);

    void OnZKeyDown();
    void OnXKeyDown();

    void OnUpKeyDown();
    void OnDownKeyDown();
    void OnLeftKeyDown();
    void OnRightKeyDown();

    bool IsValidSpawnPosition(learning::Vector2f pos, int selfCheck = -1);

    void FixedUpdate();
    void LogicUpdate();

    void CreatePlayer();
    void CreateEnemy();
    void CreateCoffia();

    void UpdatePlayerInfo();
	void UpdateEnemyInfo(int index, float deltaTime);

    int FindCollisionAt(learning::Vector2f pos, int selfIndex, int ignoreIndex);
    int FindClosestObjectAt(learning::Vector2f pos, int selfIndex = -1, int ignoreIndex = -1);
    bool IsOverlapping(learning::Vector2f pos, float radius, GameObject* targetObject);

    GameObject* GetPlayer() const { return (GameObject*)m_GameObjectPtrTable[0]; }
    GameObject* GetGameObject(int index) const { return (GameObject*)m_GameObjectPtrTable[index]; }

private:
    HDC m_hFrontDC = nullptr;
    HDC m_hBackDC = nullptr;
    HBITMAP m_hBackBitmap = nullptr;
    HBITMAP m_hDefaultBitmap = nullptr;

    // [CHECK] #8. 게임 타이머를 사용하여 프레임을 관리하는 예시.
    GameTimer* m_pGameTimer = nullptr;
    float m_fDeltaTime = 0.0f;
    float m_fFrameCount = 0.0f;

    // [CHECK] #8. 게임 오브젝트를 관리하는 컨테이너.
    GameObjectBase** m_GameObjectPtrTable = nullptr;

    struct MOUSE_POS
    {
        int x = 0;
        int y = 0;

        bool operator!=(const MOUSE_POS& other) const
        {
            return (x != other.x || y != other.y);
        }
    };

    MOUSE_POS m_MousePos = { 0, 0 };
    MOUSE_POS m_MousePosPrev = { 0, 0 };

    MOUSE_POS m_PlayerTargetPos = { 0, 0 };
    MOUSE_POS m_EnemySpawnPos = { 0, 0 };

    bool keys[256] = {};    // 특정 키가 눌려있는지 확인
    
    std::function<void()> OnKey[256];       // 키가 눌릴때 나올 메서드
    std::function<void(int, int)> OnKeyDown[256];   // 키가 딱 눌린 순간에만 나올 메서드
    std::function<void(int, int)> OnKeyUp[256];   // 키가 딱 눌린 순간에만 나올 메서드
};