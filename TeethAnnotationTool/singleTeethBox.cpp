//#include <QButton>
#include "singleTeethBox.h"

singleTeethBox::singleTeethBox(QWidget *parent) : QWidget(parent)
{
	_part_name = QString::fromStdString("");
	_result_fd = "";
	_original_obj_fn = "";
	setupLayout();
}

singleTeethBox::singleTeethBox(QWidget *parent, std::string name) : QWidget(parent)
{
	_part_name = QString::fromStdString(name);
	_result_fd = "";
	setupLayout();
}

void singleTeethBox::setupLayout()
{
	_layout = new QVBoxLayout;
	_button = new QPushButton(_part_name);
	_ckbox = new QCheckBox();
	_layout->addWidget(_button);
	_layout->addWidget(_ckbox);
	_layout->setAlignment(_button, Qt::AlignCenter);
	_layout->setAlignment(_ckbox, Qt::AlignCenter);
	_ckbox->setAttribute(Qt::WA_TransparentForMouseEvents);
	_ckbox->setFocusPolicy(Qt::NoFocus);
	this->setLayout(_layout);
	connect(_button, SIGNAL(clicked()), this, SLOT(handleButton()));
}

void singleTeethBox::handleButton()
{
	if (_result_fd.empty())
	{
		QMessageBox::information(
			this,
			tr("Error!"),
			tr("No folder selected. Please select a folder first!"));
		return;
	}
	_popup = new SegmentQApp(_part_name.toStdString(), _original_obj_fn, _result_fd);
	connect(_popup->buttonBox, SIGNAL(accepted()), this, SLOT(checkBox()));
	_popup ->show();
}

void singleTeethBox::checkBox()
{
	_ckbox->setChecked(true);
}

void singleTeethBox::setResultFd(std::string result_fd)
{
	_result_fd = result_fd;
}

void singleTeethBox::setOriginalObj(std::string original_obj_fn)
{
	_original_obj_fn = original_obj_fn;
}