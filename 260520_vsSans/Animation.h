#pragma once
#include <string>
#include <vector>
#include "Utillity.h"
using namespace std;
using Vector2f = learning::Vector2f;

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
	void AddKeyFrame(const KeyFrame& keyFrame);

	const vector<KeyFrame>& GetKeyFrames() const { return keyFrames; }

	void SetIsLooping(bool loop) { isLooping = loop; }
	bool GetIsLooping() const {	return isLooping; }

private:
	vector<KeyFrame> keyFrames;
	bool isLooping = false; // 애니메이션이 반복되는지 여부
	float time;
};

class Animator
{
private:
	vector<AnimationClip> animationClips;
	int currentClipIndex = -1;
};