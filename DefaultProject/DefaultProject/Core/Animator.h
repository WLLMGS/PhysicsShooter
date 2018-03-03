#pragma once
class Animator
{
public:
	Animator(int framesPerSecond, int amountOfFrames);
	void Reset(int framesPerSecond, int amountOfFrames);
	void Update(float elapsedSec);
	int CurrentFrame() const;
private:
	int m_CurrentFrame;
	int m_FramesPerSecond;
	int m_AmountOfFrames;
	float m_Timer;
};

