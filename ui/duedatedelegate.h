#ifndef RELATIVEDUEDELEGATE_H
#define RELATIVEDUEDELEGATE_H

#include <QStyledItemDelegate>
#include <QObject>

class RelativeDueDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit RelativeDueDelegate(QObject* parent = nullptr);  //	Verhindert implizite Konvertierungen und Kopien, sorgt für explizite Initialisierung.

    // paint is geting overriten to chance the lock like text color etc
    void paint(QPainter* painter, const QStyleOptionViewItem& option,
               const QModelIndex& index) const override ;

    QString displayText(const QVariant& value,const QLocale& locale)const override;

    // custom row sizes
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const override;//deddeeee
};

#endif // RELATIVEDUEDELEGATE_H
