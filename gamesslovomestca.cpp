//Автор : voronov vladimir
//Суть игры состоит в том ,в том что пк передаются слова и он их по буквам замешивает ,
//потом пользователю надо угадывать слова.Если пользователь не угадывает слово, то кол-во очков снижается .Также он может использовать подсказку за очки
//Пользователь может выбрать сложность игры ,смотря какая сложность от чего будет зависеть длина слова
//Сейчас игра :имеет три сложности,от которых зависит кол-во очков на подсказдки и неугадывания слов,при поражении показывает макс очков и кол-во отгаданых слов,
//Идею взял с книги "Доусон_М_Изучаем_С++_через_программирование" , очень сильно развивает практику написание программ на С++ 
//Можно это уменьшить в несколько раз , но пока лень 

#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <ctime>
#include <windows.h>



using namespace std;


int main() {

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    enum difficlys { EASY, MEDIUM, HARD, NUM_DIFFICLYS };
    enum field { WORD, HIRT, NUM_SIZE };
    string diff;
    string write_word;
    int diff_numberd;
    const int COUNT_WORD = 7;
    int maxscore = -1;
    int k = 0;
    int score = 0;
    int count = 0;
    cout << "Добро пожаловать в 'СловоМесяво'\n";
    cout << "ПК будет мешать буквы слов,ваша задача как игрока отгадать их\n";
    cout << "Если у вас не получается отгадать то напишите'гони подсказку'\n";
    cout << "Если хочется покинуть ссесию игры то пишите 'ну и бредятина'\n";
    cout << "Ну шо погнали\n";
    cout << "Выберите сложность(Easy,Medium,Hard):";

    string WORDS[NUM_DIFFICLYS][COUNT_WORD][NUM_SIZE] = {
       {
           {"броня","Защищает от пуль"},
           {"тьма","Ничего не видно"},
           {"помидор","Краснющий и вкусный"},
           {"очки","вещь для глаз"},
           {"специальность","ивт что "},
           {"мазь","на лицо"},
           {"взрыв","бабадум"},
       },
       {
            {"матрица","монитор линал и фильм"},
           {"жегалкин","дискретная математика"},
           {"клавиатура","девайс пк"},
           {"развлечения","когда хочеся на бутылку сесть"},
           {"антарктида","материк"},
           {"дежавю","ощущение как будто это было"},
           {"злопамятливый","когда запомнил пакость и будешь её каждый раз вспоминать"},
       },
       {
            {"дезоксирибонуклеиновая","днк"},
           {"университет","вгу"},
           {"физкультура","8 00 утра блин вставать"},
           {"факультет","физфак"},
           {"репозиторий","гит хаб"},
           {"программирование","писать текст для машины с++,с#"},
           {"одноклассники","это те люди которые учились с тобой в школе"},
       },

    };
    do {

        srand(static_cast<unsigned int>(time(0)));
        int random_word = (rand() % COUNT_WORD);

        while ((diff != "Easy") && (diff != "Medium") && (diff != "Hard"))
        {
            cin >> diff;
            if (diff == "Easy")
            {
                k = 1;
                diff_numberd = 0;
            }
            else if (diff == "Medium") {
                k = 2;
                diff_numberd = 1;
            }
            else if (diff == "Hard") {
                k = 5;
                diff_numberd = 2;
            }
            else {
                cout << "\nError\n";
            }
        }

        string theword = WORDS[diff_numberd][random_word][WORD];
        string thehirt = WORDS[diff_numberd][random_word][HIRT];
        string word_itog = theword;
        int lenght = word_itog.size();
        for (int i = 0; i < lenght; i++)
        {
            int index1 = (rand() % lenght);
            int index2 = (rand() % lenght);
            char bukba = word_itog[index1];
            word_itog[index1] = word_itog[index2];
            word_itog[index2] = bukba;
        }

 

        cout << "Слово : " << word_itog << "\n";
        cout << "\nКоличество очков : " << score << "\n\n";
        if (count > 0) {
            cout << "\n\nВводите слово: ";
            getline(cin, write_word);
        }
        else {
            cout << "\n\nВводите слово: ";
            getline(cin, write_word);
            getline(cin, write_word);
        }
        while ((write_word != theword) && (write_word != "ну и бредятина") && (score > 0))
        {
            if (write_word == "гони подсказку")
            {
                score -= 60 * k;
                cout << "\nКоличество очков: " << score << "\n\n";
                cout << thehirt << "\n";
            }
            else {
                score -= 80 * k;
                cout << "Ну и Бред,ну ты подумай лох чтоли\n";
                cout << "\nКоличество очков: " << score << "\n\n";
            }
            cout << "\n\nВводите слово: ";
            getline(cin, write_word);
            cout << "\nКоличество очков: " << score << "\n\n";

        }
        if (write_word == theword)
        {
            count++;
            score += 150;
            if (score > maxscore)
            {
                maxscore = score;
            }
            cout << "\nКрасава,ЮХУ!!!!!!!\n\n";
        }


    } while ((score > 0) && (write_word != "ну и бредятина"));
    cout << "\nGame Over!!!\n\n";
    cout << "Максимальное количество очков :" << maxscore << "\n";
    cout << "\nКоличество слов :" << count << "\n";

}
