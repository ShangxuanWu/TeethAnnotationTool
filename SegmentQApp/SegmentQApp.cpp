#include "SegmentQApp.h"

// Handle mouse events
class MouseInteractorStyle2 : public vtkInteractorStyleTrackballCamera
{
public:
	static MouseInteractorStyle2* New();
	MouseInteractorStyle2() {
		selectionPoints = vtkSmartPointer<vtkPoints>::New();
	}
	vtkTypeMacro(MouseInteractorStyle2, vtkInteractorStyleTrackballCamera);

	virtual void OnLeftButtonDown()
	{
		int* clickPos = this->GetInteractor()->GetEventPosition();

		// this picker gets ID
		vtkSmartPointer<vtkCellPicker> cell_picker =
			vtkSmartPointer<vtkCellPicker>::New();
		cell_picker->SetTolerance(0.0005);

		cell_picker->Pick(clickPos[0], clickPos[1], 0, this->GetDefaultRenderer());
		int cell_id = cell_picker->GetCellId();
		if (cell_id != -1) { // picked a point on the mesh
			vtkIdType npts;
			vtkIdType* pts;
			float new_pair_dist = INT_MAX;

			tmpMesh->GetCellPoints(cell_id, npts, pts);
			if (npts < 1) {
				std::cout << "Wrong cell_id with no points! Exiting!" << endl;
				exit(2);
			}
			double pos[3];
			tmpMesh->GetPoint(pts[0], pos);

			if (clicked_point.size() == 0) {
				clicked_point.push_back(pts[0]);
				selectionPoints->InsertNextPoint(pos[0], pos[1], pos[2]);
			}
			else { // clicked_point.size() >= 1
				double pos_old[3];
				tmpMesh->GetPoint(clicked_point[clicked_point.size() - 1], pos_old);

				new_pair_dist = pow(pos_old[0] - pos[0], 2) + pow(pos_old[1] - pos[1], 2) + pow(pos_old[2] - pos[2], 2);
				cout << "The distance is " << new_pair_dist << endl;
				if (new_pair_dist <= MAX_TWO_PT_DST) { // if the newly clicked point is not too faraway from old one
					clicked_point.push_back(pts[0]);
					selectionPoints->InsertNextPoint(pos[0], pos[1], pos[2]);
					if (clicked_point.size() >= 2) {
						calculateNewPath();
					}
				}
				else {
					std::cout << "Clicked point too faraway from the last point, thus not recording this point!" << endl;
				}
			}
			// draw point
			if (clicked_point.size() == 1 || (clicked_point.size() > 1 && new_pair_dist <= MAX_TWO_PT_DST)) {
				std::cout << "Drawing sphere!" << endl;
				//Create a sphere
				vtkSmartPointer<vtkSphereSource> sphereSource =
					vtkSmartPointer<vtkSphereSource>::New();

				sphereSource->SetCenter(pos[0], pos[1], pos[2]);
				sphereSource->SetRadius(0.1);

				//Create a mapper and actor
				vtkSmartPointer<vtkPolyDataMapper> mapper =
					vtkSmartPointer<vtkPolyDataMapper>::New();
				mapper->SetInputConnection(sphereSource->GetOutputPort());

				vtkSmartPointer<vtkActor> actor =
					vtkSmartPointer<vtkActor>::New();
				actor->SetMapper(mapper);
				actor->GetProperty()->SetColor(0.0, 1.0, 1.0); // draw color

				this->GetDefaultRenderer()->AddActor(actor);
			}
		}
		this->Interactor->Render();
	}

	virtual void OnRightButtonDown()
	{
		vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
	}

	virtual void OnRightButtonUp()
	{
		vtkInteractorStyleTrackballCamera::OnLeftButtonUp();
	}

	virtual void OnMiddleButtonDown() {
		vtkSmartPointer<vtkSelectPolyData> loop =
			vtkSmartPointer<vtkSelectPolyData>::New();
		loop->SetInputConnection(tmpMeshInput);
		loop->SetLoop(selectionPoints);
		loop->GenerateSelectionScalarsOn();
		loop->SetSelectionModeToLargestRegion(); //negative scalars inside
		std::cout << "Finished selecting region" << std::endl;
		// how to render?
		clip = vtkSmartPointer<vtkClipPolyData>::New();
		clip->SetInputConnection(loop->GetOutputPort());

		vtkSmartPointer<vtkPolyDataMapper> clipMapper =
			vtkSmartPointer<vtkPolyDataMapper>::New();
		clipMapper->SetInputConnection(clip->GetOutputPort());

		vtkSmartPointer<vtkLODActor> clipActor =
			vtkSmartPointer<vtkLODActor>::New();
		clipActor->SetMapper(clipMapper);

		this->GetDefaultRenderer()->AddActor(clipActor);
		this->Interactor->Render();




		// should save a piece of cutted obj file here 


		/*
		vtkSmartPointer<vtkOBJWriter> writer =
			vtkSmartPointer<vtkOBJWriter>::New();
		std::string output_fn = "aaa.obj";
		writer->SetInputData(clip->GetOutput());
		writer->SetFileName(output_fn.c_str());
		writer->Update();
		std::cout << "Selected mesh saved!" << std::endl;*/
	}

	void SetMeshInput(vtkAlgorithmOutput* a) {
		tmpMeshInput = a;
	}

	void SetMesh(vtkPolyData* a) {
		tmpMesh = a;
	}

	vtkSmartPointer<vtkPolyData> getPartMesh()
	{
		return clip->GetOutput();
	}

private:
	std::vector<int> clicked_point;
	vtkSmartPointer<vtkDijkstraGraphGeodesicPath> dijkstra;
	vtkSmartPointer<vtkPolyDataMapper> pathMapper;
	vtkSmartPointer<vtkActor> pathActor;
	vtkSmartPointer<vtkPoints> selectionPoints;
	vtkAlgorithmOutput* tmpMeshInput;
	vtkPolyData* tmpMesh;
	vtkSmartPointer<vtkClipPolyData> clip;

	// draw new path from this 
	void calculateNewPath() {
		// new renderer for nearest path
		dijkstra = vtkSmartPointer<vtkDijkstraGraphGeodesicPath>::New();
		dijkstra->SetInputConnection(tmpMeshInput);
		dijkstra->SetStartVertex(clicked_point[clicked_point.size() - 2]);
		dijkstra->SetEndVertex(clicked_point[clicked_point.size() - 1]);
		dijkstra->Update();

		// Create a mapper and actor
		pathMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
		pathMapper->SetInputConnection(dijkstra->GetOutputPort());

		pathActor = vtkSmartPointer<vtkActor>::New();
		pathActor->SetMapper(pathMapper);
		pathActor->GetProperty()->SetColor(1, 0, 0); // Red
		pathActor->GetProperty()->SetLineWidth(4);

		this->GetDefaultRenderer()->AddActor(pathActor);
	}
};

vtkStandardNewMacro(MouseInteractorStyle2);


SegmentQApp::SegmentQApp()
{
	throw std::invalid_argument("SegmentQApp should be initialized with parameter!");
	/*	
	_vlayout = new QVBoxLayout(this);
	_hlayout = new QHBoxLayout(this);

	createInstruction();
	createQVTKWidget();
	createBottomButtons();

	setLayout(_hlayout);
	_hlayout->update();
	*/
}

SegmentQApp::SegmentQApp(std::string name, std::string original_obj_fn, std::string result_fd)
{
	setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

	_original_name = name;
	_original_obj_fn = original_obj_fn;

	_total_layout = new QVBoxLayout;
	_upper_layout = new QHBoxLayout;
	_lower_layout = new QHBoxLayout;

	createInstruction();
	createQVTKWidget();
	createBottomButtons();

	_total_layout->addLayout(_upper_layout);
	_total_layout->addLayout(_lower_layout);

	setLayout(_total_layout);
	_total_layout->update();

	setWindowTitle(QString::fromStdString(_original_name));
	
	if (config::teeth_id_hash.find(_original_name) != config::teeth_id_hash.end())
	{
		_full_result_fn = result_fd + std::to_string(config::teeth_id_hash.at(_original_name)) + ".obj";
	}
	else
	{
		throw std::invalid_argument("Invalid hashmap for toothname->id correspondence!");
	}
}

void SegmentQApp::initializeResource(std::string resource)
{
	//Q_INIT_RESOURCE(resource);
}

void SegmentQApp::createInstruction()
{
	_image = new QLabel;
	std::string resource = "SegmentQApp.qrc";
	initializeResource(resource);
	QPixmap imagePixmap(":/TeethAnnotationTool/Teeth.png");
	int w = WIDGET_H / INSTRUCTION_RATIO;
	int h = WIDGET_H;
	_square_painter = new QPainter(&imagePixmap);
	_square_painter->setPen(*(new QColor(255, 0, 0, 255)));
	int x = config::teeth_position_hash.at(_original_name).first;
	int y = config::teeth_position_hash.at(_original_name).second;
	_square_painter->drawRect(x-SQUARE_SIZE/2, y-SQUARE_SIZE/2, SQUARE_SIZE, SQUARE_SIZE);
	//QPixmap imagePixmap("C:\\Users\\shangxuanu\\Desktop\\AnnotationUI\\SegmentQApp\\Teeth.png");
	_image->setPixmap(imagePixmap.scaled(w, h));
	//_image->setFixedHeight(WIDGET_H/2);
	//_image->setFixedWidth(WIDGET_W/2);
	_upper_layout->addWidget(_image);
}

void SegmentQApp::createBottomButtons()
{
	buttonBox = new QDialogButtonBox(QDialogButtonBox::Save);
	_lower_layout->addWidget(buttonBox);
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(savePartMesh()));
}


void SegmentQApp::createQVTKWidget()
{
	qvtkWidget = new QVTKWidget(this);
	qvtkWidget->setFixedHeight(WIDGET_H);
	qvtkWidget->setFixedWidth(WIDGET_W);
	_upper_layout->addWidget(qvtkWidget);

	vtkSmartPointer<vtkSTLReader> reader =
		vtkSmartPointer<vtkSTLReader>::New();
	reader->SetFileName(_original_obj_fn.c_str());
	reader->Update();

	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(reader->GetOutputPort());

	vtkSmartPointer<vtkActor> actor =
		vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);

	vtkSmartPointer<vtkRenderer> renderer =
		vtkSmartPointer<vtkRenderer>::New();

	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	renderWindowInteractor->SetRenderWindow(this->qvtkWidget->GetRenderWindow());

	renderer->AddActor(actor);
	renderer->SetBackground(.3, .6, .3); // Background color green

	this->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
	this->qvtkWidget->GetRenderWindow()->Render();

	style = vtkSmartPointer<MouseInteractorStyle2>::New();
	style->SetDefaultRenderer(renderer);
	style->SetMeshInput(reader->GetOutputPort());
	style->SetMesh(reader->GetOutput());

	renderWindowInteractor->SetInteractorStyle(style);
}

void SegmentQApp::savePartMesh()
{
	vtkSmartPointer<vtkPolyData> clipped_output = style->getPartMesh();

	vtkSmartPointer<vtkOBJWriter> writer =
		vtkSmartPointer<vtkOBJWriter>::New();
	writer->SetInputData(clipped_output);
	writer->SetFileName(_full_result_fn.c_str());
	writer->Update();
	std::cout << "Selected mesh saved!" << std::endl;

	accept();
}

std::string SegmentQApp::replaceStrSpace(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			str[i] = '_';
		}
	}
	return str;
}