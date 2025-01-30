#ifndef RELATIVEDUEDELEGATE_H
#define RELATIVEDUEDELEGATE_H

#include <QStyledItemDelegate>
#include <QObject>

class RelativeDueDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit RelativeDueDelegate(QObject parent = nullptr);

    // paint is geting overriten to chance the lock like text color etc
    void paint(QPainterpainter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;

    // custom row sizes
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const override;
};

#endif // RELATIVEDUEDELEGATE_H
