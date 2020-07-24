//
// Created by 徐溶延 on 2020/7/24.
//

#ifndef BCQN_TET_TET_READER_H
#define BCQN_TET_TET_READER_H
#include <string>

#include <Eigen/Dense>

#include "vtk.h"

namespace xry_mesh {
	namespace io {
		/**
		 * 读取.TET文件
		 * @param filename	文件名
		 * @param V 		顶点
		 * @param TET 		四面体
		 */
		void readTet(const std::string &filename, Eigen::Matrix3Xd &V, Eigen::Matrix4Xi &TET);

		/**
		 * 将四面体网格写为vtk文件
		 * @param V
		 * @param TET
		 */
		void writeTet2Vtk(const std::string &filename, const Eigen::Matrix3Xd &V, const Eigen::Matrix4Xi &TET);
	}
}


#endif //BCQN_TET_TET_READER_H
