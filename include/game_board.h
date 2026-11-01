#pragma once
#include <QWidget>
#include "engine.h"

class GameBoard: public QWidget {
	Q_OBJECT;
	public:
		GameBoard(engine::BoardState& state, QWidget* parent=nullptr);
	protected:
		void paintEvent(QPaintEvent* event);
};
