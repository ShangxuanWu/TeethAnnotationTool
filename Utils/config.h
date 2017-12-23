#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

// for SegmentQApp
#define MAX_TWO_PT_DST 150 
#define WIDGET_H 1280
#define WIDGET_W 1280
#define INSTRUCTION_RATIO 1.4
#define BOARDER 20
#define SQUARE_SIZE 30

// for TeethAnnotationTool
namespace debug_files {
	const std::string basemesh_fd = "C:\\Users\\shangxuanu\\Desktop\\teeth\\basemesh";
	const std::string recmesh_fd = "C:\\Users\\shangxuanu\\Desktop\\teeth\\sample_scan";
}

namespace config {
	const std::vector<std::string> recmesh_fns = {
		"BiteScan.stl",
		"BiteScan2.stl",
		"LowerJawScan.stl",
		"UpperJawScan.stl"
	};
	const std::vector<std::string> part_names = {
		"CentralIncisor",
		"LateralIncisor",
		"Canine",
		"FirstPremolar",
		"SecondPremolar",
		"FirstMolar",
		"SecondMolar",
		"ThirdWisdomMolar",
	};
	const std::vector<std::string> h_directions = {
		"Left",
		"Right",
	};
	const std::vector<std::string> v_directions = {
		"Upper",
		"Lower",
	};
	const std::string gum_name = "Gums";
	const std::string path_line_string = "Please choose a folder from file menu.";
	const std::string wrong_path_line_string = "Wrong path! Please choose a folder from file menu.";
	const std::vector<std::string> valid_folder_files = {
		"UpperJawScan.stl",
		"LowerJawScan.stl",
	};
	// id for each teeth
	const std::unordered_map<std::string, int> teeth_id_hash = {
		{ "Upper Right ThirdWisdomMolar", 1 },
		{ "Upper Right SecondMolar", 2 },
		{ "Upper Right FirstMolar", 3 },
		{ "Upper Right SecondPremolar", 4 },
		{ "Upper Right FirstPremolar", 5 },
		{ "Upper Right Canine", 6 },
		{ "Upper Right LateralIncisor", 7 },
		{ "Upper Right CentralIncisor", 8 },
		{ "Upper Left CentralIncisor", 9 },
		{ "Upper Left LateralIncisor", 10 },
		{ "Upper Left Canine", 11 },
		{ "Upper Left FirstPremolar", 12 },
		{ "Upper Left SecondPremolar", 13 },
		{ "Upper Left FirstMolar", 14 },
		{ "Upper Left SecondMolar", 15 },
		{ "Upper Left ThirdWisdomMolar", 16 },
		{ "Lower Left ThirdWisdomMolar", 17 },
		{ "Lower Left SecondMolar", 18 },
		{ "Lower Left FirstMolar", 19 },
		{ "Lower Left SecondPremolar", 20 },
		{ "Lower Left FirstPremolar", 21 },
		{ "Lower Left Canine", 22 },
		{ "Lower Left LateralIncisor", 23 },
		{ "Lower Left CentralIncisor", 24 },
		{ "Lower Right CentralIncisor", 25 },
		{ "Lower Right LateralIncisor", 26 },
		{ "Lower Right Canine", 27 },
		{ "Lower Right FirstPremolar", 28 },
		{ "Lower Right SecondPremolar", 29 },
		{ "Lower Right FirstMolar", 30 },
		{ "Lower Right SecondMolar", 31 },
		{ "Lower Right ThirdWisdomMolar", 32 },
	};
	// where to draw the red square, wrt the original image not the scaled one
	// <x,y>
	const std::unordered_map<std::string, std::pair<int, int>> teeth_position_hash = {
		{ "Upper Right ThirdWisdomMolar", { 108,230 } },
		{ "Upper Right SecondMolar",{ 109,186 } },
		{ "Upper Right FirstMolar",{ 116,151 } },
		{ "Upper Right SecondPremolar",{ 125,114 } },
		{ "Upper Right FirstPremolar",{ 130,89 } },
		{ "Upper Right Canine",{ 142,63 } },
		{ "Upper Right LateralIncisor",{ 165, 45 } },
		{ "Upper Right CentralIncisor",{ 196, 41 } },
		{ "Upper Left CentralIncisor",{ 229, 37 } },
		{ "Upper Left LateralIncisor", {261, 44} },
		{ "Upper Left Canine",{ 281, 63 } },
		{ "Upper Left FirstPremolar",{ 290, 89 } },
		{ "Upper Left SecondPremolar",{ 302, 117 } },
		{ "Upper Left FirstMolar",{ 306, 150 } },
		{ "Upper Left SecondMolar",{ 312, 187 } },
		{ "Upper Left ThirdWisdomMolar",{ 315, 226 } },
		{ "Lower Left ThirdWisdomMolar",{ 314, 298 } },
		{ "Lower Left SecondMolar",{ 308, 337 } },
		{ "Lower Left FirstMolar",{ 297, 373 } },
		{ "Lower Left SecondPremolar",{ 286, 406 } },
		{ "Lower Left FirstPremolar",{ 282, 435 } },
		{ "Lower Left Canine",{ 268, 459 } },
		{ "Lower Left LateralIncisor",{ 245, 469 } },
		{ "Lower Left CentralIncisor",{ 223, 471 } },
		{ "Lower Right CentralIncisor",{ 198, 472 } },
		{ "Lower Right LateralIncisor",{ 174, 470 } },
		{ "Lower Right Canine",{ 155, 457 } },
		{ "Lower Right FirstPremolar",{ 139, 436 } },
		{ "Lower Right SecondPremolar",{ 131, 409 } },
		{ "Lower Right FirstMolar",{ 120, 374 } },
		{ "Lower Right SecondMolar",{ 113, 334 } },
		{ "Lower Right ThirdWisdomMolar",{ 108, 299 } },
	};
}