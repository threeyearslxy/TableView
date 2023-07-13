#include "MyTableView.h"
#include "TableModel.h"

MyTableView::MyTableView(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	QTableView *pTableView = new QTableView(this);
	TableModel *pModel = new TableModel(this);

	// ���õ���ѡ�С����һ�����졢��ͷ���������ޱ߿��
	pTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	pTableView->horizontalHeader()->setStretchLastSection(true);
	pTableView->horizontalHeader()->setHighlightSections(false);
	pTableView->verticalHeader()->setVisible(false);
	pTableView->setShowGrid(false);
	pTableView->setFrameShape(QFrame::NoFrame);
	pTableView->setSelectionMode(QAbstractItemView::SingleSelection);
	pTableView->setModel(pModel);

	// �������ݡ����½���
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
