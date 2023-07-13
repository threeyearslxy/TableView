#pragma once

#include <QObject>
#include <QAbstractItemModel>
#include <QColor>
#include <QTableView>
struct FileRecord
{
	QString strFilePath;
	bool bChecked;
};

class TableModel : public QObject,public QAbstractTableModel
{
	Q_OBJECT

public:
	TableModel(QObject *parent = nullptr);
	~TableModel();
	void updateData(QList<FileRecord> recordList);
	int rowCount(const QModelIndex &parent) const;
	int columnCount(const QModelIndex &parent) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	QVariant data(const QModelIndex &index, int role) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
private:
	QList<FileRecord> m_recordList;
};
