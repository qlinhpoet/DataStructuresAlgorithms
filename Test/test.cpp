#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    do
    {
        try
        {
            int max = 44;
            int div = 0;
            qInfo() << "enter a number to divide by (or Zero for an issue)";
            std::cin >> div;

            if(div == 0)
            {
                throw QString("cannot devide to zero");
            }

            int answer = max / div; //posible exception
            qInfo() << answer;
        }
        catch (QString e)
        {
            qWarning() <<"catch:" <<e;
        }
        catch(int e)
        {

        }
        catch(...)
        {
            //catch all - very bad case
        }

    }while (true);

    return a.exec();
}
