/*Segéd parancs
    g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch13drill `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
{

	//méret
	int szelesseg = 800;
	int magassag = 1000;

	//window ablak létrehozása
	Simple_window ablak {Point{100,100},szelesseg,magassag,"My window"};

	//grid
	Lines grid;
	int meret = 800;
	int negyzet = 100;

	for(int i = negyzet; i <= meret; i += negyzet)
	{
		grid.add(Point{i,0}, {Point(i, meret)});
		grid.add(Point{0,i}, {Point(meret, i)});
	}

	//piros csík
	Vector_ref<Rectangle> csik;

	for (int i = 0; i < meret;i +=negyzet)
	{
		csik.push_back(new Rectangle{Point{i,i},100,100});
		csik[csik.size()-1].set_fill_color(Color::red);
		ablak.attach(csik[csik.size()-1]);
	}

	//képek
	Vector_ref<Image> kepek;
	kepek.push_back(new Image(Point{0,300}, "logo.jpg"));
	kepek.push_back(new Image(Point{0,300}, "logo.jpg"));
	kepek.push_back(new Image(Point{0,300}, "logo.jpg"));

	constexpr int kep_meret = 200;

	for(int i = 0; i< kepek.size(); ++i)
	{
		ablak.attach(kepek[i]);
	}

	//kép mozgás
}