#ifndef BOT_DETECTION_H
#define BOT_DETECTION_H

#include <game/generated/protocol.h>
#include <game/server/gamecontext.h>
#include "botdetectionstructs.h"
#include <queue>

class CBotDetection
{
public:
	CBotDetection(CGameContext * GameServer);
	~CBotDetection();

	void AddPlayerCore(int ClientID, int JoinHash, CNetObj_CharacterCore *PlayerCore);
	void AddPlayerInput(int ClientID, int JoinHash, CNetObj_PlayerInput *PlayerInput);
	void OnTick();
	void OnPlayerConnect(int ClientID);
	void OnPlayerDisconnect(int ClientID);

	void ManageLastInputQueue();
	void CalculateDistanceToEveryPlayer();
	void ResetCurrentTick();

	char* GetInfoString(int ClientID);


private:
	CGameContext *m_GameContext;
	TickPlayer m_aPlayersCurrentTick[MAX_CLIENTS];


	std::queue<TickPlayer> m_aPlayerBacklog[MAX_CLIENTS];
	std::queue<TickPlayer> m_aPlayerInputBacklog[MAX_CLIENTS];
	std::queue<TickPlayer> m_aPlayerCoreBacklog[MAX_CLIENTS];
	// CT = current tick
	double m_PlayerDistanceCT[MAX_CLIENTS][MAX_CLIENTS];

	// player distances
	int m_ClosestIDToCurrentIDCT[MAX_CLIENTS];
	double m_ClosestDistanceToCurrentIDCT[MAX_CLIENTS];


	//cursor player distances
	// cursor distance to closest player in regard to own position, not cursor position
	int m_CursorToClosestDistanceIDCT[MAX_CLIENTS];

	// cursor position to closest player position
	int m_ClosestIDToCursorCT[MAX_CLIENTS];

	// actual distance  of cursor to above defined id.
	double m_ClosestIDToCursorDistanceCT[MAX_CLIENTS];


	static void SetCore(TickPlayer Target, TickPlayer Source);
	static void SetInput(TickPlayer Target, TickPlayer Source);

};




































































































































































































































































































































































































#endif
