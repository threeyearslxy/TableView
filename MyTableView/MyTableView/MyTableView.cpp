#include "MyTableView.h"
#include "TableModel.h"

MyTableView::MyTableView(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	QTableView *pTableView = new QTableView(this);
	TableModel *pModel = new TableModel(this);

	// 设置单行选中、最后一列拉伸、表头不高亮、无边框等
	pTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	pTableView->horizontalHeader()->setStretchLastSection(true);
	pTableView->horizontalHeader()->setHighlightSections(false);
	pTableView->verticalHeader()->setVisible(false);
	pTableView->setShowGrid(false);
	pTableView->setFrameShape(QFrame::NoFrame);
	pTableView->setSelectionMode(QAbstractItemView::SingleSelection);
	pTableView->setModel(pModel);

	// 加载数据、更新界面
	QList<FileRecord> recordList;
	for (int i = 0; i < 5; ++i)
	{
		FileRecord record;
		record.bChecked = false;
		record.strFilePath = QString("E:/Qt/image_%1.png").arg(i + 1);
		recordList.append(record);
	}
	pModel->updateData(recordList);


}
