#include "cbase.h"
#include "mom_replay.h"

#pragma once
class CMomentumReplayGhostEntity : public CBaseAnimating
{
    DECLARE_CLASS(CMomentumReplayGhostEntity, CBaseAnimating);
	DECLARE_DATADESC();
public:
	const char* GetGhostModel();
	void SetGhostModel(const char* model);
	//Increments the steps intelligently.
	void updateStep();

	void EndRun();
	void StartRun();
	void HandleGhost();
	void clearRunData();

    bool m_bIsActive;
    int m_nStartTick;

protected:
	virtual void Think(void);
    virtual void Spawn(void);
    virtual void Precache(void);

private:
    char m_pszModel[256], m_pszMapName[256];
	replay_frame_t* currentStep; 
    replay_frame_t* nextStep;	

    int step;
    Color m_ghostColor;
};
