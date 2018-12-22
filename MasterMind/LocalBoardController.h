#pragma once
#include "BoardController.h"
#include "LocalOperationController.h"

class LocalBoardController
	: public BoardController, public LocalOperationController
{
public:
	LocalBoardController(MasterMind* game);
	~LocalBoardController();

	// Heredado vía BoardController
	virtual std::vector<Round*>& getRounds() override;
	virtual int getPlayedRounds() override;
	virtual void action(bool victory) override;

	// Heredado vía LocalOperationController
	virtual void accept(IOperationControllerVisitor * operationControllerVisitor) override;
	bool isFinished();

private:
	bool finished;
};

