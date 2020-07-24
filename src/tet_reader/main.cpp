//
// Created by 徐溶延 on 2020/7/24.
//

#include "tet_reader.h"

#include <filesystem>
#include <dbg.h>

using namespace xry_mesh::io;


int main(int argc, char **argv) {
	const static std::string PATH = argv[1];
	/**
	 * 遍历目录下所有文件
	 */
	for (auto &p : std::filesystem::directory_iterator(PATH)) {
		const std::string path = p.path().string();
		const std::string filename = path.substr(path.find_last_of("/\\"));
		auto index = filename.find_last_of('.');
		const std::string prefix = filename.substr(0, index);
		const std::string suffix = filename.substr(index + 1);

		//convert
		if (suffix == "tet" || suffix == "TET") {
			Eigen::Matrix3Xd V;
			Eigen::Matrix4Xi TET;
			readTet(p.path().string(), V, TET);
			const std::string output_path = PATH + prefix + ".vtk";
			dbg(output_path);
			writeTet2Vtk(output_path, V, TET);
		}
	}
	return 0;
}

