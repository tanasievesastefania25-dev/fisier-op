 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class Fisier
{
	private:
	const int codFisier;
	string numeFisier;
	int nrAccesari;
	string* editori;
	float dimensiuneFisier;
	string extensie;
	static int contor;
	public:
	//constructor fara parametrii
		Fisier():codFisier(contor++)
		{
		this->numeFisier="fisier";
		this->nrAccesari=0;
		this->editori=NULL;
		this->dimensiuneFisier=0;
		this->extensie="NA";


	}
	//constructor cu parametrii-validari
		Fisier(string numeFisierInit,int nrAccesariInit,string* editoriInit,float dimensiuneFisierInit,string extensieInit) :codFisier(contor++)
		{
			if (numeFisierInit.length()>=5)
			{
				this->numeFisier=numeFisierInit;
		}
			else
			{
				this->numeFisier = "fisier";
			}
			if (nrAccesariInit > 0 && editoriInit!=nullptr)
			{
				this->nrAccesari=nrAccesariInit;
			
				this->editori = new string[nrAccesariInit];
				for (int i = 0;i < nrAccesariInit;i++)
				{
					this->editori[i] = editoriInit[i];
				}
			}
			else
			{
				this->editori = nullptr;
				this->nrAccesari=0;
			}
			
			
			if (dimensiuneFisierInit > 0)
			{
				this->dimensiuneFisier=dimensiuneFisierInit;
			}
			else {
				this->dimensiuneFisier=0;
			}
			if (extensieInit.length() > 0)
			{
				this->extensie=extensieInit;
			}
			else {
				this->extensie="NA";
			}


		}
		//destructor
		~Fisier()
		{
		if (editori != NULL)
		{
			delete[]this->editori;
		}
		}
		//constructor copiere pt float dimFisier string extensie
		Fisier(const Fisier& f):codFisier(contor++)
		{
		this->extensie=f.extensie;
		this->dimensiuneFisier=f.dimensiuneFisier;
		this->nrAccesari=f.nrAccesari;
		this->numeFisier=f.numeFisier;
		if (f.editori != NULL && f.nrAccesari > 0)
		{
			this->editori = new string[f.nrAccesari];
			for (int i = 0;i < f.nrAccesari;i++)
			{
				this->editori[i] = f.editori[i];
			}
		}
		else
		{
			this->editori = NULL;
			this->nrAccesari=0;
		}
		
		}

		//getter si setter pt pt float dimFisier string extensie
		float getDimensiuneFisier()
		{
			return this->dimensiuneFisier;
		}
		void setDimensiuneFisier(float dimensiuneFisierNou)
		{
			if (dimensiuneFisierNou > 0)
			{
				this->dimensiuneFisier=dimensiuneFisierNou;
			}
		}
		string getExtensie()
		{
			return this->extensie;
		}
		void setExtensie(string extensieNoua)
		{
			if (extensieNoua.length() > 0)
			{
				this->extensie=extensieNoua;
			}
		}



		//op =
		Fisier& operator=(const Fisier& f)
		{

			if (this == &f)
			{
				return *this;
			}
			if (editori != NULL)
			{
				delete[]this->editori;
			}
			this->extensie = f.extensie;
			this->dimensiuneFisier = f.dimensiuneFisier;
			this->nrAccesari = f.nrAccesari;
			this->numeFisier = f.numeFisier;
			if (f.editori != NULL && f.nrAccesari > 0)
			{
				this->editori = new string[f.nrAccesari];
				for (int i = 0;i < f.nrAccesari;i++)
				{
					this->editori[i] = f.editori[i];
				}
			}
			else
			{
				this->editori = NULL;
				this->nrAccesari = 0;
			}
			return *this;




		}
		//op<<
		friend ostream& operator<<(ostream& out, const Fisier& f)
		{
			out<<f.codFisier<<endl;
			out<<f.numeFisier<<endl;
			out<<f.extensie<<endl;
			out<<f.dimensiuneFisier<<endl;
			out<<f.nrAccesari<<endl;
			for (int i = 0;i < f.nrAccesari;i++)
			{
				out<<f.editori[i]<<endl;
			}
			out<<endl;
			return out;

		}
		//op>>
		friend istream& operator>>(istream& in, Fisier& f)
		{
			//nume
			cout<<"Nume fisier:";
			string nume;
			getline(in,nume);
			if (nume.length() >= 5)
			{
				f.numeFisier=nume;
			}
			
			//extensie
			cout<<"extensie:";
			string extensie;
			getline(in,extensie);
			if (extensie.length() > 0)
			{
				f.extensie=extensie;
			}
			//nr accesari si editori
			cout<<"Nr accesari:";
			int nr;
			in>>nr;
			in.ignore();
			if (f.editori != nullptr)
			{
				delete[]f.editori;
			}
			if (nr > 0)
			{
				f.nrAccesari=nr;
				f.editori=new string[nr];
				for (int i = 0;i < nr;i++)
				{
					cout<<"editor"<<i+1;": ";
					getline(in, f.editori[i]);
				}
			}
			else
			{
				f.nrAccesari=0;
				f.editori=nullptr;
			}

			return in;
		}
		//op > compara lungimea numelor fisierelor
		bool operator>(const Fisier& f)
		{
			if (this->numeFisier.length() > f.numeFisier.length())
			{
				return true;
		}
			else
			{
				return false;
			}
		}
		//++ pt dimensiune fisier

		//pre incrementare ++f
		Fisier& operator++()
		{
			this->dimensiuneFisier++;
			return *this;
		}
		//post incrementare f++
		Fisier& operator++(int)
		{
			Fisier copie=*this;
			this->dimensiuneFisier++;
			return copie;
		}
		//op + pt dimensiune fisier
		//ob+val f1+5
		Fisier& operator+(float val)
		{
			Fisier copie=*this;
			copie.dimensiuneFisier +=val;
			return copie;

		}
		//ob+ob f!+f2
		Fisier& operator+(const Fisier& f)
		{
			Fisier copie=*this;
			copie.dimensiuneFisier+=f.dimensiuneFisier;
			return copie;
		}
		//val+val
		friend Fisier operator+(float val, Fisier f)
		{
			f.dimensiuneFisier+=val;
			return f;
		}
		//cast la float 
		explicit operator float()
		{
			return this->dimensiuneFisier;
		}
		//cast la int 
		explicit operator int()
		{
			return this->nrAccesari;
		}
		// op () fara param dim medie per acesare 
		float operator()()
		{
			if (this->nrAccesari == 0)
			{
				return 0;
				return this->dimensiuneFisier/this->nrAccesari;
			}
		}
		/*class Director
		{
			private:
			string nume;
			Fisier fisier;
		public:
			Director()
			{
				this->nume="Documente";

		}
			Director(string numeInit, Fisier f)
			{
				this->nume=numeInit;
				this->fisier=f;
		}
			string getNume()
			{
				return this->nume;
		}
			Fisier getFisier()
			{
				return this->fisier;
		}
			void setFisier(Fisier f)
			{
				this->getFisier=f;
		}
			void afisare()
			{
				cout << "Director: " << this->nume << endl;
				cout << this->fisier << endl;
			}*/

	};








		



int Fisier::contor=0;
int main() {


//constr fara param
Fisier f1;
cout<<f1<<endl;

//constr cu param
string editori[]{"Ana","Ion"};
Fisier f2("raport.docx",2,editori,34.1f,"docx");
cout<<f2<<endl;


//constr de copiere
Fisier f3=f2;
cout<<f3<<endl;

//op=
f1=f2;
cout<<f1<<endl;

//get si set
cout<<f1.getDimensiuneFisier()<<endl;
f1.setDimensiuneFisier(12.5f);
cout << f1.getDimensiuneFisier() << endl;
cout<<f1.getExtensie()<<endl;
f1.setExtensie("pdf");
cout << f1.getExtensie() << endl;


//>>
Fisier f5;
cin>>f5;
cout<<f5<<endl;

//>
Fisier f6("ocument.txt",2,editori,12.3f,"txt");
cout<<(f6>f2)<<endl;

// ++
Fisier f7("raport.docx",2,editori,10.0f,"docx");
cout<<(++f7).getDimensiuneFisier()<<endl;
cout<<(++f7).getDimensiuneFisier()<<endl;
cout<<f7.getDimensiuneFisier()<<endl;

//+
Fisier f8("raport.docx",2,editori,10.0f,"docx");
Fisier r1=f8+5;
Fisier r2=f8+f8;
Fisier r3=5+f8;
cout<<r1.getDimensiuneFisier()<<endl;
cout<<r2.getDimensiuneFisier()<<endl;
cout << r3.getDimensiuneFisier() << endl;
//cast
Fisier f9("raport.docx", 2, editori, 10.0f, "docx");
cout<<(float)f9<<endl;
cout<<(int)f9<<endl;
//op ()
cout<<f9()<<endl;


return 0;
}