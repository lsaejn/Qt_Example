#include "QListWidget_Alime.h"

#include <QListWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

QListWidget_Alime::QListWidget_Alime(QWidget *parent)
    : QWidget(parent)
{
    //ui.setupUi(this);
    setStyleSheet("background:rgba(25,27,31,255);");
    setContentsMargins(0, 0, 0, 0);
    
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    vLayout->setContentsMargins(0, 0, 0, 0);

    QListWidget* listWidget = new QListWidget(this);
    QLabel* btn = new QLabel(this);
    btn->setText("推荐");
    btn->setStyleSheet("color:rgb(173,175,178);");
    vLayout->addWidget(btn);

    //推荐列表 列表样式
    listWidget->setStyleSheet("QListWidget{color:rgb(173,175,178); background:rgb(25,27,31);border:0px solid gray;}"
        "QListWidget::Item{height:30px;border:0px solid gray;padding-left:0;}"
        "QListWidget::Item:hover{color:rgb(255,255,255);background:transparent;border:0px solid gray;}"
        "QListWidget::Item:selected{border-image:url(images/listwidget_h.png); color:rgb(255,255,255);border:0px solid gray;}"
        "QListWidget::Item:selected:active{background:#00FFFFFF;color:#FFFFFF;border-width:0;}"
    );
    QListWidgetItem* add_item_1 = new QListWidgetItem(listWidget);
    add_item_1->setIcon(QIcon("./images/music.png"));
    add_item_1->setText("发现音乐");
    QListWidgetItem* add_item_2 = new QListWidgetItem(listWidget);
    add_item_2->setIcon(QIcon("./images/fm.png"));
    add_item_2->setText("私人FM");
    QListWidgetItem* add_item_3 = new QListWidgetItem(listWidget);
    add_item_3->setIcon(QIcon("./images/video.png"));
    add_item_3->setText("MV");
    QListWidgetItem* add_item_4 = new QListWidgetItem(listWidget);
    add_item_4->setIcon(QIcon("./images/friend.png"));
    add_item_4->setText("朋友");
    vLayout->addWidget(listWidget);

    //我的音乐列表
    QLabel* label2 = new QLabel(this);
    label2->setStyleSheet("color:rgb(173,175,178);");
    label2->setText("我的音乐");
    vLayout->addWidget(label2);

    listWidget_mymusic = new QListWidget(this);
    connect(listWidget_mymusic, &QListWidget::clicked, this, &QListWidget_Alime::OnListItemClicked);

    listWidget_mymusic->setStyleSheet("QListWidget{color:rgb(173,175,178); background:rgb(25,27,31);border:0px solid gray;}"
        "QListWidget::Item{height:30px;border:0px solid gray;padding-left:15;}"
        "QListWidget::Item:hover{color:rgb(255,255,255);background:transparent;border:0px solid gray;}"
        "QListWidget::Item:selected{border-image:url(images/listwidget_h.png); color:rgb(255,255,255);border:0px solid gray;}"
        "QListWidget::Item:selected:active{background:#00FFFFFF;color:#FFFFFF;border-width:0;}");
    QListWidgetItem* add_item_5 = new QListWidgetItem(listWidget_mymusic);
    add_item_5->setIcon(QIcon("./images/music_1.png"));
    add_item_5->setText("本地音乐");
    QListWidgetItem* add_item_6 = new QListWidgetItem(listWidget_mymusic);
    add_item_6->setIcon(QIcon("./images/download.png"));
    add_item_6->setText("下载管理");
    QListWidgetItem* add_item_7 = new QListWidgetItem(listWidget_mymusic);
    add_item_7->setIcon(QIcon("./images/yun.png"));
    add_item_7->setText("我的音乐云盘");
    QListWidgetItem* add_item_8 = new QListWidgetItem(listWidget_mymusic);
    add_item_8->setIcon(QIcon("./images/diantai.png"));
    add_item_8->setText("我的电台");
    QListWidgetItem* add_item_9 = new QListWidgetItem(listWidget_mymusic);
    add_item_9->setIcon(QIcon("./images/shoucang.png"));
    add_item_9->setText("我的搜藏");

    
    vLayout->addWidget(listWidget_mymusic);

    //比方说，我们希望做出pkpmmain那样的工具条，里面全是button
    QListWidget *m_pListWgt = new QListWidget(this);
    m_pListWgt->setSpacing(12);
    m_pListWgt->setMaximumHeight(120);
    m_pListWgt->setMovement(QListView::Static);
    m_pListWgt->setViewMode(QListView::IconMode);
    m_pListWgt->setFlow(QListView::TopToBottom);
    //m_pListWgt->setFlow(QListView::LeftToRight);

    for (int i = 0; i < 15; i++)
    {
        QListWidgetItem* item = new QListWidgetItem(QIcon(":/QListWidget_Alime/back"), "Test", m_pListWgt);
        item->setData(Qt::ToolTipRole, "Test");
        m_pListWgt->addItem(item);
    }
    vLayout->addWidget(m_pListWgt);

    resize(400, 600);
}


void QListWidget_Alime::OnListItemClicked(const QModelIndex& index)
{
    int row = listWidget_mymusic->currentRow();
    if (row == index.row())
    {
        QListWidgetItem* item=listWidget_mymusic->currentItem();
        QString name=item->text();
        qDebug() << name<<"\n";
    }
}
