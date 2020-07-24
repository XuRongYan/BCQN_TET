//
// Created by 徐溶延 on 2020/7/24.
//

#include "tet_reader.h"

#include <fstream>


namespace xry_mesh {
	namespace io {

		void readTet(const std::string &filename, Eigen::Matrix3Xd &V, Eigen::Matrix4Xi &TET) {
			const std::string name = filename.substr(filename.find_last_of("/\\"));
			auto index = name.find_last_of('.');
			const std::string SUFFIX = name.substr(index + 1);

			assert(SUFFIX == "tet" || SUFFIX == "TET");

			int vert_num, tet_num;
			float x, y, z;
			int i1, i2, i3, i4;

			FILE *tet_file = std::fopen(filename.c_str(), "rt");

			std::fscanf(tet_file, "#num of vertex: %d\n", &vert_num);
			std::fscanf(tet_file, "#num of tetrahedra: %d\n\n", &tet_num);

			V = Eigen::MatrixXd::Zero(3, vert_num);
			TET = Eigen::MatrixXi::Zero(4, tet_num);

			for (int i = 0; i < vert_num; i++) {
				fscanf(tet_file, "%f %f %f\n", &x, &y, &z);

				V(0, i) = x;
				V(1, i) = y;
				V(2, i) = z;
			}

			fscanf(tet_file, "\n");

			for (int i = 0; i < tet_num; i++) {
				fscanf(tet_file, "%d %d %d %d\n", &i1, &i2, &i3, &i4);

				TET(0, i) = i1;
				TET(1, i) = i2;
				TET(2, i) = i3;
				TET(3, i) = i4;
			}

			fclose(tet_file);

		}

		void writeTet2Vtk(const std::string &filename, const Eigen::Matrix3Xd &V, const Eigen::Matrix4Xi &TET) {
			std::ofstream ofs(filename);
			tet2vtk(ofs, V.data(), V.cols(), TET.data(), TET.cols());
		}
	}
}