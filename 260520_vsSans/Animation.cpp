#include "Animation.h"
#include "GameObject.h"
#include "RenderHelp.h"
#include <vector>
#include <cmath>
#include <iostream>

void AnimationClip::AddKeyFrame(const KeyFrame& keyFrame)
{
	keyFrames.push_back(keyFrame);
}

float AnimationClip::GetLength() const
{
	float length = 0.0f;

	for (const KeyFrame& keyFrame : keyFrames)
	{
		float endTime = keyFrame.startTime + keyFrame.duration;
		if (endTime > length)
			length = endTime;
	}

	return length;
}

void Animator::AddAnimationClip(const AnimationClip& clip)
{
	animationClips.push_back(clip);
}

void Animator::SetCurrentClip(const string& clipName)
{
	for (size_t i = 0; i < animationClips.size(); ++i)
	{
		if (animationClips[i].GetName() == clipName)
		{
			currentClipIndex = static_cast<int>(i);
			time = 0.0f; // 클립이 변경될 때 시간 초기화
			return;
		}
	}
	currentClipIndex = -1; // 클립을 찾지 못한 경우
}

void Animator::Play(float deltaTime)
{
	// 현재 클립이 유효한지 확인
	if (currentClipIndex < 0) return;
	if (currentClipIndex >= animationClips.size()) return;

	// 현재 클립과 키프레임 목록 가져오기
	AnimationClip& currentClip = animationClips[currentClipIndex];
	vector<KeyFrame>& keyFrames = currentClip.GetKeyFrames();

	// 키프레임이 없는 경우 스킵
	if (keyFrames.empty()) return;

	// 시간 업데이트
	deltaTime *= 0.001f; // 밀리초 단위를 초 단위로 변환
	time += deltaTime;

	// 클립 길이 확인
	float clipLength = currentClip.GetLength();

	// 시간이 클립 길이를 초과하면 반복 혹은 멈춤
	if (time > clipLength)
	{
		if (currentClip.GetIsLooping())
		{
			time = fmodf(time, clipLength);

			for (KeyFrame& keyFrame : keyFrames)
			{
				keyFrame.SetHasStarted(false);
			}
		}
		else
		{
			time = clipLength;
		}
	}

	// 키프레임 적용
	for ( KeyFrame& keyFrame : keyFrames)
	{
		float startTime = keyFrame.startTime;
		float endTime = keyFrame.startTime + keyFrame.duration;

		if (keyFrame.duration <= 0.0f)
		{
			if (time >= startTime && !keyFrame.hasStarted)
			{
				keyFrame.SetHasStarted(true);
				ApplyKeyFrame(keyFrame, 1.0f);
			}

			continue;
		}

		if (time < startTime || time > endTime)
			continue;

		// 키 프레임이 시작될 때를 기준으로 startValue를 설정 (1회 초기화)
		if (!keyFrame.hasStarted && keyFrame.useCurrentAsStartValue) 
		{
			keyFrame.SetHasStarted(true);
			renderHelp::BitmapInfo* bitmapInfo = owner->GetBitmapInfo(keyFrame.ImageName);

			if (bitmapInfo) {
				if (keyFrame.type == KeyFrameType::Position) {
					keyFrame.SetStartValue(bitmapInfo->GetAniTransform().position);
				}
				else if (keyFrame.type == KeyFrameType::Scale) {
					keyFrame.SetStartValue(bitmapInfo->GetAniTransform().scale);
				}
				else if (keyFrame.type == KeyFrameType::Rotation) {
					keyFrame.SetStartValue(bitmapInfo->GetAniTransform().rotation);
				}
			}
		}

		float t = 0.0f;

		if (keyFrame.duration > 0.0f)
		{
			t = (time - startTime) / keyFrame.duration;
		}
		else
		{
			t = 1.0f;
		}

		float easedT = ApplyEase(t, keyFrame.easeType);

		ApplyKeyFrame(keyFrame, easedT);
	}
}

void Animator::SetOwner(GameObject* owner)
{
	this->owner = owner;
}

float Animator::ApplyEase(float t, EaseType easeType)
{
	switch (easeType)
	{
	case EaseType::Linear:
		return t;
	case EaseType::EaseIn:
		return t * t;
	case EaseType::EaseOut:
		return 1.0f - (1.0f - t) * (1.0f - t);
	case EaseType::EaseInOut:
		return t * t * (3.0f - 2.0f * t);
	}
	return t;
}

void Animator::ApplyKeyFrame(const KeyFrame& keyFrame, float t)
{
	if (owner == nullptr) return;
	renderHelp::BitmapInfo* bitmapInfo = owner->GetBitmapInfo(keyFrame.ImageName);
	
	//bitmapInfo->SetActive(false);

	//cout << "Drawing Bitmap: " << bitmapInfo->GetName() << ", Frame: " << bitmapInfo->GetActive() << endl;

	switch (keyFrame.type) {
		case KeyFrameType::Position:
		{
			Vector2f value = keyFrame.startValue + (keyFrame.endValue - keyFrame.startValue) * t;
			bitmapInfo->GetAniTransform().SetPosition(value);
			break;
		}
		case KeyFrameType::Rotation:
		{
			float angle = keyFrame.startValue.x + (keyFrame.endValue.x - keyFrame.startValue.x) * t;
			bitmapInfo->GetAniTransform().SetRotation(angle);
			break;
		}
		case KeyFrameType::Scale:
		{
			Vector2f scale = keyFrame.startValue + (keyFrame.endValue - keyFrame.startValue) * t;
			bitmapInfo->GetAniTransform().SetScale(scale);
			break;
		}
		case KeyFrameType::Sprite:
			bitmapInfo->SetCurFrame(keyFrame.valueInt);
			break;
		case KeyFrameType::Active:
			bitmapInfo->SetActive(keyFrame.valueInt == 1);
			break;
	}
	
}


KeyFrame AnimationClip::MakePositionKeyFrame(float startTime, const string& imageName, Vector2f startValue, Vector2f endValue, float duration, EaseType easeType)
{
	KeyFrame keyFrame;
	keyFrame.startTime = startTime / 60.0f;
	keyFrame.ImageName = imageName;
	keyFrame.type = KeyFrameType::Position;
	keyFrame.startValue = startValue;
	keyFrame.endValue = endValue;
	keyFrame.duration = duration / 60.0f;
	keyFrame.easeType = easeType;
	keyFrame.useCurrentAsStartValue = false;
	return keyFrame;
}

KeyFrame AnimationClip::MakeRotationKeyFrame(float startTime, const string& imageName, float startAngle, float endAngle, float duration, EaseType easeType)
{
	KeyFrame keyFrame;
	keyFrame.startTime = startTime / 60.0f;
	keyFrame.ImageName = imageName;
	keyFrame.type = KeyFrameType::Rotation;
	keyFrame.startValue = Vector2f(startAngle, 0); // 회전은 x값만 사용
	keyFrame.endValue = Vector2f(endAngle, 0);
	keyFrame.duration = duration / 60.0f;
	keyFrame.easeType = easeType;
	keyFrame.useCurrentAsStartValue = false;
	return keyFrame;
}

KeyFrame AnimationClip::MakeScaleKeyFrame(float startTime, const string& imageName, Vector2f startScale, Vector2f endScale, float duration, EaseType easeType)
{
	KeyFrame keyFrame;
	keyFrame.startTime = startTime / 60.0f;
	keyFrame.ImageName = imageName;
	keyFrame.type = KeyFrameType::Scale;
	keyFrame.startValue = startScale;
	keyFrame.endValue = endScale;
	keyFrame.duration = duration / 60.0f;
	keyFrame.easeType = easeType;
	keyFrame.useCurrentAsStartValue = false;
	return keyFrame;
}

KeyFrame AnimationClip::MakePositionKeyFrame(float startTime, const string& imageName, Vector2f endValue, float duration, EaseType easeType)
{
	KeyFrame keyFrame;
	keyFrame.startTime = startTime / 60.0f;
	keyFrame.ImageName = imageName;
	keyFrame.type = KeyFrameType::Position;
	keyFrame.endValue = endValue;
	keyFrame.duration = duration / 60.0f;
	keyFrame.easeType = easeType;
	keyFrame.useCurrentAsStartValue = true;
	return keyFrame;
}

KeyFrame AnimationClip::MakeRotationKeyFrame(float startTime, const string& imageName, float endAngle, float duration, EaseType easeType)
{
	KeyFrame keyFrame;
	keyFrame.startTime = startTime / 60.0f;
	keyFrame.ImageName = imageName;
	keyFrame.type = KeyFrameType::Rotation;
	keyFrame.endValue = Vector2f(endAngle, 0);
	keyFrame.duration = duration / 60.0f;
	keyFrame.easeType = easeType;
	keyFrame.useCurrentAsStartValue = true;
	return keyFrame;
}

KeyFrame AnimationClip::MakeScaleKeyFrame(float startTime, const string& imageName, Vector2f endScale, float duration, EaseType easeType)
{
	KeyFrame keyFrame;
	keyFrame.startTime = startTime / 60.0f;
	keyFrame.ImageName = imageName;
	keyFrame.type = KeyFrameType::Scale;
	keyFrame.endValue = endScale;
	keyFrame.duration = duration / 60.0f;
	keyFrame.easeType = easeType;
	keyFrame.useCurrentAsStartValue = true;
	return keyFrame;
}

KeyFrame AnimationClip::MakeSpriteKeyFrame(float startTime, const string& imageName, int frameIndex)
{
	KeyFrame keyFrame;
	keyFrame.startTime = startTime / 60.0f;
	keyFrame.ImageName = imageName;
	keyFrame.type = KeyFrameType::Sprite;
	keyFrame.valueInt = frameIndex;
	keyFrame.duration = 0.0f;
	keyFrame.easeType = EaseType::Linear; // 스프라이트 변경은 보간이 필요 없으므로 Linear로 설정
	return keyFrame;
}

KeyFrame AnimationClip::MakeActiveKeyFrame(float startTime, const string& imageName, bool isActive)
{
	KeyFrame keyFrame;
	keyFrame.startTime = startTime / 60.0f;
	keyFrame.ImageName = imageName;
	keyFrame.type = KeyFrameType::Active;
	keyFrame.valueInt = isActive ? 1 : 0;
	keyFrame.duration = 0.0f;
	keyFrame.easeType = EaseType::Linear; // 활성화 여부 변경은 보간이 필요 없으므로 Linear로 설정
	return keyFrame;
	}