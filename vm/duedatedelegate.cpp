#include "duedatedelegate.h"
#include <QPainter>
#include <QDateTime>

RelativeDueDelegate::RelativeDueDelegate(QObject parent)
    : QStyledItemDelegate(parent)
{}

// Du hast ein relatives datum also im vergleich zum jetztigen datum zeigt er dann morgen übermorgen in x y tage nechste woche etc

void RelativeDueDelegate::paint(QPainterpainter, const QStyleOptionViewItem &option,
                                const QModelIndex &index) const
{
    // Get due date
    QString dueDateStr = index.model()->data(index, Qt::DisplayRole).toString();
    QDateTime dueDate = QDateTime::fromString(dueDateStr, "yyyy-MM-dd");
    QDateTime now = QDateTime::currentDateTime();

    // calc relative time
    QString displayText;
    if (now.daysTo(dueDate) > 0)
        displayText = QString("%1 days left").arg(now.daysTo(dueDate)); // .arg replaces placeholders like %1, %2 with "the right content". In diesem fall mit .nowdaysTo(DueDate)
    else
        displayText = QString("Overdue by %1 days").arg(-now.daysTo(dueDate));

    QStyleOptionViewItem modifiedOption(option);
    modifiedOption.text = displayText;

    QStyledItemDelegate::paint(painter, modifiedOption, index);
}

QSize RelativeDueDelegate::sizeHint(const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const
{
    return QStyledItemDelegate::sizeHint(option, index);
}
