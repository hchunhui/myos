#ifndef _GRAPHMAN_H_FILE_INCLUDED_

#define _GRAPHMAN_H_FILE_INCLUDED_

#include "Graph.h"
#include "Game.h"

class CGraphMan
{
public:
	void Update();
	void SetGame(CGame * Game);
	void SetGraph(CGraph * Graph);
private:
	CGraph * m_pGraph;
	CGame * m_pGame;
};

#endif
