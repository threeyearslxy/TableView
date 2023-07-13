#include "TableModel.h"
#define CHECK_BOX_COLUMN 0
#define File_PATH_COLUMN 1

TableModel::TableModel(QObject *parent)
	: QAbstractTableModel(parent)
{

}

TableModel::~TableModel()
{

}

// ���±������
void TableModel::updateData(QList<FileRecord> recordList)
{
	m_recordList = recordList;
	beginResetModel();
	endResetModel();
}

// ����
int TableModel::rowCount(const QModelIndex &parent) const
{
	return m_recordList.count();
}

// ����
int TableModel::columnCount(const QModelIndex &parent) const
{
	return 2;
}

// ���ñ��������
bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (!index.isValid())
		return false;

	int nColumn = index.column();
	FileRecord record = m_recordList.at(index.row());
	switch (role)
	{
	case Qt::DisplayRole:
	{
		if (nColumn == File_PATH_COLUMN)
		{
			record.strFilePath = value.toString();

			m_recordList.replace(index.row(), record);
			emit dataChanged(index, index);
			return true;
		}
	}
	case Qt::CheckStateRole:
	{
		if (nColumn == CHECK_BOX_COLUMN)
		{
			record.bChecked = (value.toInt() == Qt::Checked);

			m_recordList.replace(index.row(), record);
			emit dataChanged(index, index);
			return true;
		}
	}
	default:
		return false;
	}
	return false;
}

// ���������
QVariant TableModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	int nRow = index.row();
	int nColumn = index.column();
	FileRecord record = m_recordList.at(nRow);

	switch (role)
	{
	case Qt::TextColorRole:
		return QColor(Qt::white);
	case Qt::TextAlignmentRole:
		return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
	case Qt::DisplayRole:
	{
		if (nColumn == File_PATH_COLUMN)
			return record.strFilePath;
		return "";
	}
	case Qt::CheckStateRole:
	{
		if (nColumn == CHECK_BOX_COLUMN)
			return record.bChecked ? Qt::Checked : Qt::Unchecked;
	}
	default:
		return QVariant();
	}

	return QVariant();
}

// ��ͷ����
QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	switch (role)
	{
	case Qt::TextAlignmentRole:
		return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
	case Qt::DisplayRole:
	{
		if (orientation == Qt::Horizontal)
		{
			if (section == CHECK_BOX_COLUMN)
				return QStringLiteral("״̬");

			if (section == File_PATH_COLUMN)
				return QStringLiteral("�ļ�·��");
		}
	}
	default:
		return QVariant();
	}

	return QVariant();
}

// ����ѡ�С��ɸ�ѡ
Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return QAbstractItemModel::flags(index);

	Qt::ItemFlags flags = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
	if (index.column() == CHECK_BOX_COLUMN)
		flags |= Qt::ItemIsUserCheckable;

	return flags;
}
