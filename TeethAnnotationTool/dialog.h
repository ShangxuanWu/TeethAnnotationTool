#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <string>
#include "../Utils/config.h"
#include "../Utils/utils.h"
#include "singleTeethBox.h"

class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QString;
class QFileDialog;

class Dialog : public QDialog
{
	Q_OBJECT

public:
	Dialog();
public slots:
	void openFolder();

private:
	void createMenu();
	void createPathBar();
	void createHorizontalGroupBox();
	void createBottomButtons();
	int numButtons = config::part_names.size();

	QVBoxLayout *main_layout;

	QMenuBar *menuBar;

	// for buttons
	singleTeethBox **buttons;
	QPushButton *finish_button;
	//QDialogButtonBox *buttonBox;
	QGridLayout *total_button_layout;

	// for menu
	QMenu *fileMenu;
	QAction *exitAction;	
	QAction *openAction;
	QString now_dir;

	// for path textbox
	QHBoxLayout *path_line_layout;
	QLabel *path_label;
	QLineEdit *path_line;
	QString _now_dir;
};

#endif // DIALOG_H