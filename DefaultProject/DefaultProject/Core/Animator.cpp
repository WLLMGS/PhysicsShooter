#include "Animator.h"


Animator::Animator(int framesPerSecond, int AmountOfFrames) :
	m_AmountOfFrames{AmountOfFrames - 1},
	m_CurrentFrame{},
	m_FramesPerSecond{framesPerSecond},
	m_Timer{}
{}

void Animator::Reset(int framesPerSecond, int amountOfFrames)
{
	m_FramesPerSecond = framesPerSecond;
	m_AmountOfFrames = amountOfFrames - 1;
	m_CurrentFrame = 0;
	m_Timer = 0.0f;
}

void Animator::Update(float elapsedSec)
{
	m_Timer += elapsedSec;

	if (m_Timer > 1.0f / m_FramesPerSecond)
	{
		m_Timer = 0.0f;
		++m_CurrentFrame;
		if (m_CurrentFrame > m_AmountOfFrames)
		{
			m_CurrentFrame = 0;
		}
	}
}

int Animator::CurrentFrame() const
{
	return m_CurrentFrame;
}
