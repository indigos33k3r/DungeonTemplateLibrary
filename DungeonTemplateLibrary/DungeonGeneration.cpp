﻿#include "DTL.hpp"
#include <array>
#include <iostream>

constexpr char a[]{"aaa"};
constexpr std::array<char, 10> b{ {"aaa"} };

void loopGeneration() noexcept {
	int type{}, id{};
	while (true) {

		std::cin >> type >> id;

		switch (type)
		{
		case'0':

			break;

		default:return;
		}
	}
}

int main() {

	//std::cout << "---------- Dungeon Select ----------" << std::endl;

	//std::cout << "---------- ---------- ---------- ----------" << std::endl;



	//return 0;

	//std::cout << b.data();

	using dungeon_t = std::uint_fast8_t;
	constexpr std::size_t big_x_size{ 128 };
	constexpr std::size_t big_y_size{ 128 };
	std::array<std::array<dungeon_t, big_x_size>, big_y_size> big_dungeon_stl_matrix{ {} };


	constexpr std::size_t x_size{ 18 };
	constexpr std::size_t y_size{ 18 };

	std::array<std::array<dungeon_t, x_size>, y_size> dungeon_stl_matrix{ {} };
	//dungeon_t dungeon_default_matrix[y_size][x_size]{};
	//dungeon_t dungeon_array_matrix[x_size*y_size]{};

	dtl::RogueLikeCave<dungeon_t> rogue_like_cave(big_dungeon_stl_matrix, 0x5f);
	dtl::fileWriteFolder_All(big_dungeon_stl_matrix, "Save\\", "RogueLikeCave");
	//dtl::fileWrite_bmp(big_dungeon_stl_matrix, "Save\\bmp\\test_rl.bmp");

	//return 0;
	//---------- SimpleVoronoiIsland ----------

	dtl::dungeonPuts("-- Simple Voronoi Island STL Class --");
	dtl::dungeonInit(big_dungeon_stl_matrix);

	//dtl::fileRead(big_dungeon_stl_matrix, "Save\\dtlm\\SimpleVoronoiIsland.dtlm");

	dtl::SimpleVoronoiIsland<dungeon_t> simple_voronoi_island_stl(big_dungeon_stl_matrix);
	dtl::noiseShoreBothBool(big_dungeon_stl_matrix, 0.4);
	//dtl::dungeonStringOutputBool(big_dungeon_stl_matrix, "##", "..");

	dtl::fileWriteFolder_All(big_dungeon_stl_matrix, "Save\\","SimpleVoronoiIsland");
	//dtl::fileWriteColor_svg(big_dungeon_stl_matrix, "Save\\test_color.svg", 0xdab870, 0x756228);

	//---------- FractalIsland ----------

	dtl::dungeonPuts("-- Fractal Island STL Class --");
	dtl::dungeonInit(big_dungeon_stl_matrix);
	dtl::FractalIsland<dungeon_t> fractal_island_stl(big_dungeon_stl_matrix);
	dtl::dungeonBinarization(big_dungeon_stl_matrix, 160);
	dtl::noiseShoreBothBool(big_dungeon_stl_matrix, 0.3);
	//dtl::dungeonStringOutputBool(big_dungeon_stl_matrix, "##", "..");

	dtl::fileWriteFolder_All(big_dungeon_stl_matrix, "Save\\","FractalIsland");

	//for (std::size_t i{}; i < 100; ++i) {
	//	dtl::dungeonInit(big_dungeon_stl_matrix);
	//	dtl::RogueLikeCave<dungeon_t> rogue_like_cave2(big_dungeon_stl_matrix, 0x5f);
	//	//dtl::noiseShoreBothBool(big_dungeon_stl_matrix, 0.4);
	//	//dtl::dungeonBinarization(big_dungeon_stl_matrix, 2);
	//	//dtl::noiseShoreBothBool(big_dungeon_stl_matrix, 0.3);
	//	dtl::fileWrite_bmp(big_dungeon_stl_matrix, "Save\\RogueLikeCave\\" + std::to_string(i)+".bmp");
	//}

	//---------- ChunkIsland ----------

	dtl::dungeonPuts("-- Chunk Island STL Class --");
	dtl::dungeonInit(big_dungeon_stl_matrix);
	dtl::ChunkIsland<dungeon_t> chunk_island_stl(big_dungeon_stl_matrix);
	dtl::dungeonBinarization(big_dungeon_stl_matrix, 160);
	dtl::noiseShoreBothBool(big_dungeon_stl_matrix, 0.3);
	//dtl::dungeonStringOutputBool(big_dungeon_stl_matrix, "##", "..");

	dtl::fileWriteFolder_All(big_dungeon_stl_matrix, "Save\\","ChunkIsland");

	constexpr std::size_t ds_x_size{ 33 };
	constexpr std::size_t ds_y_size{ 33 };
	std::array<std::array<dungeon_t, ds_x_size>, ds_y_size> ds_dungeon_stl_matrix{ {} };

	//---------- SimpleDiamondSquareAverageIslandCorner ----------

	dtl::dungeonPuts("-- Simple Diamond Square Average Island Corner STL Class --");
	dtl::dungeonInit(ds_dungeon_stl_matrix);
	dtl::SimpleDiamondSquareAverageIslandCorner<dungeon_t> simple_diamond_square_average_island_corner(ds_dungeon_stl_matrix);
	dtl::dungeonBinarization<dungeon_t>(ds_dungeon_stl_matrix, 160);
	dtl::noiseShoreBothBool(ds_dungeon_stl_matrix, 0.4);
	//dtl::dungeonStringOutputBool(ds_dungeon_stl_matrix, "##", "..");

	dtl::fileWriteFolder_All(ds_dungeon_stl_matrix, "Save\\","SimpleDiamondSquareAverageIslandCorner");

	//---------- SimpleDiamondSquareAverageIsland ----------

	dtl::dungeonPuts("-- Simple Diamond Square Average Island STL Class --");
	dtl::dungeonInit(ds_dungeon_stl_matrix);
	dtl::SimpleDiamondSquareAverageIsland<dungeon_t> simple_diamond_square_average_island(ds_dungeon_stl_matrix);
	dtl::dungeonBinarization<dungeon_t>(ds_dungeon_stl_matrix, 160);
	dtl::noiseShoreBothBool(ds_dungeon_stl_matrix, 0.3);
	//dtl::dungeonStringOutputBool(ds_dungeon_stl_matrix, "##", "..");

	dtl::fileWriteFolder_All(ds_dungeon_stl_matrix, "Save\\","SimpleDiamondSquareAverageIsland");

	//---------- Border ----------

	dtl::dungeonPuts("-- Border STL Function --");
	dtl::dungeonInit(dungeon_stl_matrix);
	dtl::createBorder(dungeon_stl_matrix);
	//dtl::dungeonStringOutputBool(dungeon_stl_matrix, "##", "  ");

	dtl::fileWriteFolder_All(dungeon_stl_matrix, "Save\\", "Border");

	//dtl::dungeonPuts("-- Border Default Function --");
	//dtl::dungeonInit(dungeon_default_matrix, x_size, y_size);
	//dtl::createBorder(dungeon_default_matrix, x_size, y_size);
	////dtl::dungeonStringOutputBool(dungeon_default_matrix, x_size, y_size, "##", "  ");

	//dtl::dungeonPuts("-- Border Array Function --");
	//dtl::dungeonInit_Array(dungeon_array_matrix, x_size, y_size);
	//dtl::createBorder_Array(dungeon_array_matrix, x_size, y_size);
	////dtl::dungeonStringOutputBool_Array(dungeon_array_matrix, x_size, y_size, "##", "  ");

	//dtl::dungeonPuts("-- Border STL Class --");
	//dtl::dungeonInit(dungeon_stl_matrix);
	//dtl::Border<dungeon_t> border_stl(dungeon_stl_matrix);
	////dtl::dungeonStringOutputBool(dungeon_stl_matrix, "##", "  ");

	//dtl::dungeonPuts("-- Border Default Class --");
	//dtl::dungeonInit(dungeon_default_matrix, x_size, y_size);
	//dtl::Border<dungeon_t> border_default(dungeon_default_matrix, x_size, y_size);
	////dtl::dungeonStringOutputBool(dungeon_default_matrix, x_size, y_size, "##", "  ");

	//dtl::dungeonPuts("-- Border Array Class --");
	//dtl::dungeonInit_Array(dungeon_array_matrix, x_size, y_size);
	//dtl::Border_Array<dungeon_t> border_array(dungeon_array_matrix, x_size, y_size);
	////dtl::dungeonStringOutputBool_Array(dungeon_array_matrix, x_size, y_size, "##", "  ");

	//---------- BorderOdd ----------

	dtl::dungeonPuts("-- BorderOdd STL Function --");
	dtl::dungeonInit(dungeon_stl_matrix);
	dtl::createBorderOdd(dungeon_stl_matrix);
	//dtl::dungeonStringOutputBool(dungeon_stl_matrix, "##", "  ");

	dtl::fileWriteFolder_All(dungeon_stl_matrix, "Save\\", "BorderOdd");

	//dtl::dungeonPuts("-- BorderOdd Default Function --");
	//dtl::dungeonInit(dungeon_default_matrix, x_size, y_size);
	//dtl::createBorderOdd(dungeon_default_matrix, x_size, y_size);
	////dtl::dungeonStringOutputBool(dungeon_default_matrix, x_size, y_size, "##", "  ");

	//dtl::dungeonPuts("-- BorderOdd Array Function --");
	//dtl::dungeonInit_Array(dungeon_array_matrix, x_size, y_size);
	//dtl::createBorderOdd_Array(dungeon_array_matrix, x_size, y_size);
	////dtl::dungeonStringOutputBool_Array(dungeon_array_matrix, x_size, y_size, "##", "  ");

	//dtl::dungeonPuts("-- BorderOdd STL Class --");
	//dtl::dungeonInit(dungeon_stl_matrix);
	//dtl::BorderOdd<dungeon_t> border_odd_stl(dungeon_stl_matrix);
	////dtl::dungeonStringOutputBool(dungeon_stl_matrix, "##", "  ");

	//dtl::dungeonPuts("-- BorderOdd Default Class --");
	//dtl::dungeonInit(dungeon_default_matrix, x_size, y_size);
	//dtl::BorderOdd<dungeon_t> border_odd_default(dungeon_default_matrix, x_size, y_size);
	////dtl::dungeonStringOutputBool(dungeon_default_matrix, x_size, y_size, "##", "  ");

	//dtl::dungeonPuts("-- BorderOdd Array Class --");
	//dtl::dungeonInit_Array(dungeon_array_matrix, x_size, y_size);
	//dtl::BorderOdd_Array<dungeon_t> border_odd_array(dungeon_array_matrix, x_size, y_size);
	////dtl::dungeonStringOutputBool_Array(dungeon_array_matrix, x_size, y_size, "##", "  ");

	//---------- PointGrid ----------

	dtl::dungeonPuts("-- PointGrid STL Function --");
	dtl::dungeonInit(dungeon_stl_matrix);
	dtl::createPointGrid(dungeon_stl_matrix);
	//dtl::dungeonStringOutputBool(dungeon_stl_matrix, "##", "  ");

	dtl::fileWriteFolder_All(dungeon_stl_matrix, "Save\\", "PointGrid");

	//dtl::dungeonPuts("-- PointGrid Default Function --");
	//dtl::dungeonInit(dungeon_default_matrix, x_size, y_size);
	//dtl::createPointGrid(dungeon_default_matrix, x_size, y_size);
	//dtl::dungeonStringOutputBool(dungeon_default_matrix, x_size, y_size, "##", "  ");

	//dtl::dungeonPuts("-- PointGrid Array Function --");
	//dtl::dungeonInit_Array(dungeon_array_matrix, x_size, y_size);
	//dtl::createPointGrid_Array(dungeon_array_matrix, x_size, y_size);
	//dtl::dungeonStringOutputBool_Array(dungeon_array_matrix, x_size, y_size, "##", "  ");

	//dtl::dungeonPuts("-- PointGrid STL Class --");
	//dtl::dungeonInit(dungeon_stl_matrix);
	//dtl::PointGrid<dungeon_t> point_grid_stl(dungeon_stl_matrix);
	//dtl::dungeonStringOutputBool(dungeon_stl_matrix, "##", "  ");

	//dtl::dungeonPuts("-- PointGrid Default Class --");
	//dtl::dungeonInit(dungeon_default_matrix, x_size, y_size);
	//dtl::PointGrid<dungeon_t> point_grid_default(dungeon_default_matrix, x_size, y_size);
	//dtl::dungeonStringOutputBool(dungeon_default_matrix, x_size, y_size, "##", "  ");

	//dtl::dungeonPuts("-- PointGrid Array Class --");
	//dtl::dungeonInit_Array(dungeon_array_matrix, x_size, y_size);
	//dtl::PointGrid_Array<dungeon_t> point_grid_array(dungeon_array_matrix, x_size, y_size);
	//dtl::dungeonStringOutputBool_Array(dungeon_array_matrix, x_size, y_size, "##", "  ");

	//---------- PointGridField ----------

	dtl::dungeonPuts("-- PointGridField STL Function --");
	dtl::dungeonInit(dungeon_stl_matrix);
	dtl::createPointGridField(dungeon_stl_matrix);
	//dtl::dungeonStringOutputBool(dungeon_stl_matrix, "##", "  ");

	dtl::fileWriteFolder_All(dungeon_stl_matrix, "Save\\", "PointGridField");

	//dtl::dungeonPuts("-- PointGridField Default Function --");
	//dtl::dungeonInit(dungeon_default_matrix, x_size, y_size);
	//dtl::createPointGridField(dungeon_default_matrix, x_size, y_size);
	//dtl::dungeonStringOutputBool(dungeon_default_matrix, x_size, y_size, "##", "  ");

	//dtl::dungeonPuts("-- PointGridField Array Function --");
	//dtl::dungeonInit_Array(dungeon_array_matrix, x_size, y_size);
	//dtl::createPointGridField_Array(dungeon_array_matrix, x_size, y_size);
	//dtl::dungeonStringOutputBool_Array(dungeon_array_matrix, x_size, y_size, "##", "  ");

	//dtl::dungeonPuts("-- PointGridField STL Class --");
	//dtl::dungeonInit(dungeon_stl_matrix);
	//dtl::PointGridField<dungeon_t> point_grid_field_stl(dungeon_stl_matrix);
	//dtl::dungeonStringOutputBool(dungeon_stl_matrix, "##", "  ");

	//dtl::dungeonPuts("-- PointGridField Default Class --");
	//dtl::dungeonInit(dungeon_default_matrix, x_size, y_size);
	//dtl::PointGridField<dungeon_t> point_grid_field_default(dungeon_default_matrix, x_size, y_size);
	//dtl::dungeonStringOutputBool(dungeon_default_matrix, x_size, y_size, "##", "  ");

	//dtl::dungeonPuts("-- PointGridField Array Class --");
	//dtl::dungeonInit_Array(dungeon_array_matrix, x_size, y_size);
	//dtl::PointGridField_Array<dungeon_t> point_grid_field_array(dungeon_array_matrix, x_size, y_size);
	//dtl::dungeonStringOutputBool_Array(dungeon_array_matrix, x_size, y_size, "##", "  ");

	return 0;

	//---------- PointGridFieldPutBlock ----------

	//dtl::dungeonPuts("-- PointGridFieldPutBlock STL Function --");
	//dtl::dungeonInit(dungeon_stl_matrix);
	//dtl::createPointGridFieldPutBlock(dungeon_stl_matrix);
	//dtl::dungeonStringOutputBool(dungeon_stl_matrix, "##", "  ");

	//dtl::dungeonPuts("-- PointGridFieldPutBlock Default Function --");
	//dtl::dungeonInit(dungeon_default_matrix, x_size, y_size);
	//dtl::createPointGridFieldPutBlock(dungeon_default_matrix, x_size, y_size);
	//dtl::dungeonStringOutputBool(dungeon_default_matrix, x_size, y_size, "##", "  ");

	//dtl::dungeonPuts("-- PointGridFieldPutBlock Array Function --");
	//dtl::dungeonInit_Array(dungeon_array_matrix, x_size, y_size);
	//dtl::createPointGridFieldPutBlock_Array(dungeon_array_matrix, x_size, y_size);
	//dtl::dungeonStringOutputBool_Array(dungeon_array_matrix, x_size, y_size, "##", "  ");

	dtl::dungeonPuts("-- PointGridFieldPutBlock STL Class --");
	dtl::dungeonInit(dungeon_stl_matrix);
	dtl::PointGridFieldPutBlock<dungeon_t> point_grid_field_put_block_stl(dungeon_stl_matrix);
	//dtl::dungeonStringOutput(dungeon_stl_matrix, "  ", "##", "//");

	//dtl::dungeonPuts("-- PointGridFieldPutBlock Default Class --");
	//dtl::dungeonInit(dungeon_default_matrix, x_size, y_size);
	//dtl::PointGridFieldPutBlock<dungeon_t> point_grid_field_put_block_default(dungeon_default_matrix, x_size, y_size);
	////dtl::dungeonStringOutput(dungeon_default_matrix, x_size, y_size, "  ", "##", "//");
	//dtl::dungeonStringOutputBool(dungeon_default_matrix, x_size, y_size, "##", "  ");

	//dtl::dungeonPuts("-- PointGridFieldPutBlock Array Class --");
	//dtl::dungeonInit_Array(dungeon_array_matrix, x_size, y_size);
	//dtl::PointGridFieldPutBlock_Array<dungeon_t> point_grid_field_put_block_array(dungeon_array_matrix, x_size, y_size);
	////dtl::dungeonStringOutput_Array(dungeon_array_matrix, x_size, y_size, "  ", "##", "//");
	//dtl::dungeonStringOutputBool_Array(dungeon_array_matrix, x_size, y_size, "##", "  ");

	//---------- Reversi ----------

	dtl::dungeonPuts("-- Reversi STL Class --");
	dtl::dungeonInit(dungeon_stl_matrix);
	dtl::Reversi<dungeon_t> reversi_stl(dungeon_stl_matrix);
	dtl::dungeonStringOutput(dungeon_stl_matrix, "..", "//", "##");

	//---------- Chess ----------

	dtl::dungeonPuts("-- Chess STL Class --");
	dtl::dungeonInit(dungeon_stl_matrix);
	dtl::Chess<dungeon_t> chess_stl(dungeon_stl_matrix);
	dtl::dungeonStringOutput(dungeon_stl_matrix, "..", "aa", "AA", "bb", "BB", "cc", "CC", "dd", "DD", "ee", "EE", "ff", "FF");

	return 0;
}