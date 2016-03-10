# ![Awesome](http://www.amm.vsu.ru/images/logo.gif?raw=true) AMM

### Для коммита в данный репозиторий необходимо скинуть username!
### Результаты первой лабораторной отмечены в файле с заданиями. Срок сдачи второй лабораторной до 31 марта включительно.

Репозиторий 1 курса. 

Основное задание:
 * Разобраться как скачать репозиторий
 * Создать папку со своей фамилией и в ней создать файлик со своим заданием
 * Закомитить изменения
 * Проверить что изменения появились в git (например на этом сайте)

### Полезности:

 * Почему, зачем и за что : [Почему Git](http://habrahabr.ru/post/104198/)

 * Как все настроить и с чем его есть: [Инструкция](http://dev.call2ru.com/vs/Работа%20с%20Git.pdf)

 * Программа, которой пользовался я на лабораторной [SourceTree](https://www.sourcetreeapp.com)

Подсказка по выполнению второго задания:
Для подсчета времени выполнения можно посчитать разницу во времени до начала выполнения блока кода и после
```C++
	clock_t start;
	clock_t stop;
	start = clock();
	for (int i = 0; i < 1000; ++i)
	{
        cout << "Example operation";
	}
	stop = clock();
	double time = double(stop - start) / CLOCKS_PER_SEC;
	cout<<"time :"<<time<<endl;
```