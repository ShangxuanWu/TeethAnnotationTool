#pragma once

#include "vtkAutoInit.h" 
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingOpenGL);
VTK_MODULE_INIT(vtkRenderingFreeType);


#include <QtWidgets/QMainWindow>
#include <QVTKWidget.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QDialogButtonBox>
#include <QLabel>
#include <QPixmap>
#include <QDir>
#include <QPainter>

//#include "ui_SegmentQApp.h"

#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkSmartPointer.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkCellPicker.h>
#include <vtkClipPolyData.h>
#include <vtkLODActor.h>
#include <vtkSelectPolyData.h>
#include <vtkDijkstraGraphGeodesicPath.h>
#include <vtkProperty.h>
#include <vtkSTLReader.h>

#include <string>
#include <unordered_map>
#include "vtkOBJWriter.h"
#include "../Utils/config.h"

class MouseInteractorStyle2;

class SegmentQApp : public QDialog
{
	Q_OBJECT

public:
	SegmentQApp();
	SegmentQApp(std::string name, std::string result_fd);
	QDialogButtonBox *buttonBox;

	public slots:
		void savePartMesh();

private:
	QVBoxLayout *_total_layout;
	QHBoxLayout *_upper_layout;
	QHBoxLayout *_lower_layout;
	QLabel *_image;
	QVTKWidget *qvtkWidget;
	QPainter *_square_painter;
	vtkSmartPointer<MouseInteractorStyle2> style;

	void initializeResource(std::string resource);
	void createInstruction();
	void createQVTKWidget();
	void createBottomButtons();
	std::string replaceStrSpace(std::string str);
	std::string _full_result_fn;
	std::string _original_name;
};
