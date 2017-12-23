#pragma once
#include <string>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QMessageBox>

#include "../SegmentQApp/SegmentQApp.h"

class singleTeethBox : public QWidget {
	Q_OBJECT

public:
	singleTeethBox(QWidget *parent);
	singleTeethBox(QWidget *parent, std::string name);
public slots:
	void handleButton();
	void checkBox();
	void setResultFd(std::string result_fd);

private:
	QString _part_name;
	std::string _result_fd;
	QPushButton *_button;
	QCheckBox *_ckbox;
	QVBoxLayout *_layout;

	void setupLayout();

	SegmentQApp* _popup;
};