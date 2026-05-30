#pragma once
#include <string>
#include <vector>
#include "Utillity.h"
using namespace std;
using Vector2f = learning::Vector2f;

// 진짜 전방선언 왜 필요한지 깊게 깨달았음
// 진짜 뭐 뜬금없이 오류 40개 나서 보니까 include 서로 때려넣어서 그런거였네..
// cpp 에선 어떻게 하지 싶다가 헤더에선 전방선언하고 include를 cpp에서만 하면 되네..
// 전언 선언 넘 좋다..
class GameObject;

enum class KeyFrameType
{
	Position,	// 위치 변경
	Rotation,	// 회전
	Scale,		// 크기 변경
	Sprite,		// 스프라이트 변경
	Active,		// 활성화 여부
};

enum class EaseType
{
	Linear,
	EaseIn,
	EaseOut,
	EaseInOut,
};

struct KeyFrame
{
	float startTime;	// 애니메이션 시작 시간
	string ImageName;	// 이미지 이름
	KeyFrameType type;	// 키프레임 타입

	Vector2f startValue;	// 위치의 경우 시작 위치, 회전의 경우 시작 각도, 크기의 경우 시작 스케일
	Vector2f endValue;		// 위치의 경우 끝 위치, 회전의 경우 끝 각도, 크기의 경우 끝 스케일
	int valueInt;	// 스프라이트의 경우 프레임 인덱스, 활성화 여부의 경우 1 또는 0

	float duration;		// 애니메이션 지속 시간
	EaseType easeType;	// 보간 타입
};

class AnimationClip 
{
public:
	void SetName(const string& name) { this->name = name; }
	const string& GetName() const { return name; }

	void AddKeyFrame(const KeyFrame& keyFrame);
	const vector<KeyFrame>& GetKeyFrames() const { return keyFrames; }

	void SetIsLooping(bool loop) { isLooping = loop; }
	bool GetIsLooping() const {	return isLooping; }

	float GetLength() const;

	KeyFrame MakePositionKeyFrame(float startTime, const string& imageName, Vector2f startValue, Vector2f endValue, float duration, EaseType easeType);
	KeyFrame MakeRotationKeyFrame(float startTime, const string& imageName, float startAngle, float endAngle, float duration, EaseType easeType);
	KeyFrame MakeScaleKeyFrame(float startTime, const string& imageName, Vector2f startScale, Vector2f endScale, float duration, EaseType easeType);
	KeyFrame MakeSpriteKeyFrame(float startTime, const string& imageName, int frameIndex);
	KeyFrame MakeActiveKeyFrame(float startTime, const string& imageName, bool isActive);

private:
	string name;				// 애니메이션 클립 이름
	vector<KeyFrame> keyFrames;	// 애니메이션 키프레임 목록
	bool isLooping = false;		// 애니메이션이 반복되는지 여부
	float time;					// 각 클립마다 저장해놓고 쓸 시간 변수 (애니메이션 재생 시마다 초기화해서 사용)
};

class Animator
{
public :
	void AddAnimationClip(const AnimationClip& clip);
	void SetCurrentClip(const string& clipName);
	void Play(float deltaTime);

	void SetOwner(GameObject* owner);

private:
	float ApplyEase(float t, EaseType easeType);
	void ApplyKeyFrame(const KeyFrame& keyFrame, float t);

private:
	vector<AnimationClip> animationClips;	// 애니메이션 클립 목록
	int currentClipIndex = -1;				// 현재 재생 중인 애니메이션 클립 인덱스
	float time = 0.0f;						// 애니메이션 재생 시마다 초기화해서 사용할 시간 변수

	GameObject* owner = nullptr;	// 애니메이션을 적용할 게임 오브젝트
};