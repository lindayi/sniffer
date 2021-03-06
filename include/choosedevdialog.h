// =====================================================================================
// 
//       Filename:  choosedevdialog.h
//
//    Description:  选择适配器对话框类声明文件
//
//        Version:  1.0
//        Created:  2013年01月26日 21时01分49秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef CHOOSEDEVDIALOG_H
#define CHOOSEDEVDIALOG_H

#include <QDialog>

#include <vector>

#include "ui_choosedevdialog.h"

class  Sniffer;
struct SettingInfo;

class ChooseDevDialog : public QDialog, public Ui::ChooseDevDialog
{
	Q_OBJECT

public:
	ChooseDevDialog(QWidget *parent = 0);
	ChooseDevDialog(Sniffer *sni, QWidget *parent = 0);

	void GetUserSet(SettingInfo *settingInfo);

	void addNetDevInfo();

	int 		iOpenDevNum;
	bool 		bPromiscuous;
	bool 		bAutoBegin;
	int	 		iDataLimit;
	std::string	filterString;

private slots:
	void helpDialog();
	void setChoose(QListWidgetItem *changedElem);
	void setPromiscuousFlag(int flag);
	void setAutoBeginFlag(int flag);
	void setDataLimitValue(int iValue);
	void setFilterString(int index);

private:
	std::vector<QListWidgetItem *> devItemVector;
	Sniffer 	*sniffer;
};

#endif	// CHOOSEDEVDIALOG_H