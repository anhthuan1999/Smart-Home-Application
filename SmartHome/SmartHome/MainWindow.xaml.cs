using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace SmartHome
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		public MainWindow()
		{
			InitializeComponent();
		}

		private void Window_Loaded(object sender, RoutedEventArgs e)
		{
			Uri urion = new Uri("C:\\Users\\Tran Anh Thuan\\Desktop\\SmartHome\\SmartHome\\on.png");
			Uri urioff = new Uri("C:\\Users\\Tran Anh Thuan\\Desktop\\SmartHome\\SmartHome\\off.png");
			Uri uris = new Uri("C:\\Users\\Tran Anh Thuan\\Desktop\\SmartHome\\SmartHome\\Power.png");
			Uri uriss = new Uri("C:\\Users\\Tran Anh Thuan\\Desktop\\SmartHome\\SmartHome\\robber.png");
			Uri urig = new Uri("C:\\Users\\Tran Anh Thuan\\Desktop\\SmartHome\\SmartHome\\Gas.png");
			Uri urif = new Uri("C:\\Users\\Tran Anh Thuan\\Desktop\\SmartHome\\SmartHome\\Fire.png");
			Uri urix = new Uri("C:\\Users\\Tran Anh Thuan\\Desktop\\SmartHome\\SmartHome\\a.png");
			Uri urid = new Uri("C:\\Users\\Tran Anh Thuan\\Desktop\\SmartHome\\SmartHome\\b.png");

			BitmapImage bmion = new BitmapImage(urion);
			BitmapImage bmioff = new BitmapImage(urioff);
			BitmapImage bmis = new BitmapImage(uris);
			BitmapImage bmiss = new BitmapImage(uriss);
			BitmapImage bmig = new BitmapImage(urig);
			BitmapImage bmif = new BitmapImage(urif);
			BitmapImage bmix = new BitmapImage(urix);
			BitmapImage bmid = new BitmapImage(urid);



			imgliving1.Source = bmion;
			imgliving2.Source = bmion;
			imgtoilet.Source = bmioff;
			imgbed.Source = bmion;
			imgkitchen.Source = bmioff;

			imglivings1.Source = bmis;
			imglivings2.Source = bmis;
			imgtoilets.Source = bmis;
			imgbeds.Source = bmis;
			imgkitchens.Source = bmis;

			imgst.Source = bmiss;
			imgsg.Source = bmix;
			imgss.Source = bmiss;

			imgft.Source = bmif;
			imgfg.Source = bmix;
			imgfs.Source = bmif;

			imggt.Source = bmig;
			imggg.Source = bmid;
			imggs.Source = bmig;
		}
	}
}
