#include "Animation.h"

void AnimationClip::AddKeyFrame(const KeyFrame& keyFrame)
{
	keyFrames.push_back(keyFrame);
}