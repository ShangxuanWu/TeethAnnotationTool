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
	void setOriginalObj(std::string original_obj_fn);
	void setResultFd(std::string result_fd);

private:
	QString _part_name;
	std::string _result_fd;
	std::string _original_obj_fn;
	QPushButton *_button;
	QCheckBox *_ckbox;
	QVBoxLayout *_layout;

	void setupLayout();

	SegmentQApp* _popup;
};