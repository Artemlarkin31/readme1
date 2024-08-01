#include "readdata.h"

Read::Read(QString speek,QWidget *parent = 0)
{


    qDebug() << speek;
    QStringList datalist = speek.split(",");

    // Create a combobox to select files
    box = new QComboBox(this);
    for (int i = 0; i < datalist.size(); i++)
    {
        box->addItem(datalist[i].trimmed()); // Use trimmed() to remove any leading/trailing spaces
    }

    // Connect combobox signal to slot for reading file content
    connect(box, SIGNAL(currentIndexChanged(int)), this, SLOT(readfrom()));

    // Set initial size of the widget
    this->setFixedSize(300, 700);

    // Initialize label for displaying file content
    label = new QLabel(this);
    label->setWindowTitle("Data");
    label->setAlignment(Qt::AlignTop);
    label->setGeometry(0, 0, 300, 700);

    // Create a scroll area for the label
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setGeometry(0, 140, 300, 560); // Adjusted dimensions for scroll area
    scrollArea->setWidget(label);
    scrollArea->setWidgetResizable(true);

    // savetotxt = new QPushButton("сохранить в txt", this);
     //savetotxt->setGeometry(225,0, 75, 30);
     //connect(savetotxt, SIGNAL(clicked()), this, SLOT(onButton1Clicked()));
    // Show the widgets
    label->show();
    box->show();

    // Initially display content of the first file
    if (!datalist.isEmpty())
    {
        QString firstFile = datalist.first().trimmed(); // Get the first file name
        displayFileContent(firstFile); // Function to display content of the selected file
    }

}

Read::~Read()
{

}

void Read::readfrom()
{
    QString selectedFile = box->currentText();
    displayFileContent(selectedFile); // Function to display content of the selected file
}

void Read::displayFileContent(const QString &filename)
{
    QString data = QString::fromStdString(readFile(filename.toStdString(), "\n"));
    data1=data;
    label->setText(data);
}
/*
void Read::onButton1Clicked()
{
    QFile file("save.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Обработка ошибки открытия файла
        qWarning("Cannot open file for writing: %s", qPrintable(file.errorString()));
        return;
    }
  //  QString &text=data1;
    QTextStream out(&file);
 //   out << text;
    file.close();
}
*/
