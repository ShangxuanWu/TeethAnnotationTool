#pragma once

#include <QtWidgets/QDialog>
#include "ui_KeypointQApp.h"

class KeypointQApp : public QDialog
{
	Q_OBJECT

public:
	KeypointQApp(QWidget *parent = Q_NULLPTR);

private:
	Ui::KeypointQAppClass ui;
};
