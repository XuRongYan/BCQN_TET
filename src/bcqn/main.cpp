//
// Created by 徐溶延 on 2020/7/23.
//
#include <QApplication>
#include <cinolib/meshes/meshes.h>
#include <cinolib/gui/qt/qt_gui_tools.h>
#include <dbg.h>

int main(int argc, char **argv) {
	const std::string PATH = argv[1];
	const std::string filename = argv[2];
	cinolib::DrawableTetmesh<> m((PATH + "/" + filename).c_str());

	QApplication a(argc, argv);

	cinolib::GLcanvas gui;
	gui.push_obj(&m);
	gui.show();

	// CMD+1 to show mesh controls.
	cinolib::VolumeMeshControlPanel<cinolib::DrawableTetmesh<>> panel(&m, &gui);

	QApplication::connect(new QShortcut(QKeySequence(Qt::CTRL+Qt::Key_1), &gui), &QShortcut::activated, [&](){panel.show();});
	return a.exec();
}
