using System;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Text;
using System.IO;

namespace Challenge5
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Wellcome To Challenge 5!");

			byte[] password_bytes = new byte[]
			{
					62,
					38,
					63,
					63,
					54,
					39,
					59,
					50,
					39
			};
			String Password = Decode_Pass(password_bytes); //  "mullethat"; 
			Console.WriteLine("Password is:" + Password);
			String Note = Decode_Note();
			Console.WriteLine("Note is: " + Note); // "keep steaks for dinner"
			String Step = "magic";
			String Desc = "water"; // used exiftool
			byte[] first = Decode_Hash(Password, Note, Step, Desc);
			//Console.WriteLine(first);
			GetImage(Password, Note, Step, Desc);
		}


		static bool GetImage(String Password, String Note, String Step, String Desc)
		{
			string text = new string(new char[]
			{
				Desc[2],
				Password[6],
				Password[4],
				Note[4],
				Note[0],
				Note[17],
				Note[18],
				Note[16],
				Note[11],
				Note[13],
				Note[12],
				Note[15],
				Step[4],
				Password[6],
				Desc[1],
				Password[2],
				Password[2],
				Password[4],
				Note[18],
				Step[2],
				Password[4],
				Note[5],
				Note[4],
				Desc[0],
				Desc[3],
				Note[15],
				Note[8],
				Desc[4],
				Desc[3],
				Note[4],
				Step[2],
				Note[13],
				Note[18],
				Note[18],
				Note[8],
				Note[4],
				Password[0],
				Password[7],
				Note[0],
				Password[4],
				Note[11],
				Password[6],
				Password[4],
				Desc[4],
				Desc[3]
			});
			byte[] key = SHA256.Create().ComputeHash(Encoding.ASCII.GetBytes(text));
			Console.WriteLine("Key is:" + key);
			byte[] bytes = Encoding.ASCII.GetBytes("NoSaltOfTheEarth");
			try
			{
				byte[] ImgData = Convert.FromBase64String(GetString(Runtime_dll(), key, bytes));
				//Save or show Image
				File.WriteAllBytes("myimage.jpg", ImgData);
				return true;
			}
			catch (Exception ex)
			{
				Console.WriteLine("An error happend!");
			}
			return false;
		}

		static byte[] Runtime_dll()
		{
			String path = "C:\\Users\\REM\\Desktop\\flare\\5\\TKApp\\bin\\Runtime.dll"; // extracted this resource using dnspy
			byte[] resource = File.ReadAllBytes(path);
			return resource;
			//return (byte[])Runtime.ResourceManager.GetObject("Runtime.dll", Runtime.resourceCulture);
		}
		static string GetString(byte[] cipherText, byte[] Key, byte[] IV)
		{
			string result = null;
			using (RijndaelManaged rijndaelManaged = new RijndaelManaged())
			{
				rijndaelManaged.Key = Key;
				rijndaelManaged.IV = IV;
				ICryptoTransform cryptoTransform = rijndaelManaged.CreateDecryptor(rijndaelManaged.Key, rijndaelManaged.IV);
				using (MemoryStream memoryStream = new MemoryStream(cipherText))
				{
					using (CryptoStream cryptoStream = new CryptoStream(memoryStream, cryptoTransform, 0))
					{
						using (StreamReader streamReader = new StreamReader(cryptoStream))
						{
							result = streamReader.ReadToEnd();
						}
					}
				}
			}
			return result;
		}



		public class Todo
		{
			public string Name { get; set; }
			public string Note { get; set; }
			public bool Done { get; set; }
			public Todo(string Name, string Note, bool Done)
			{
				this.Name = Name;
				this.Note = Note;
				this.Done = Done;
			}
		}

		static String Decode_Note()
		{
			String Note = "";
			List<Todo> list = new List<Todo>();
			if (false)
			{
				list.Add(new Todo("go home", "and enable GPS", false));
			}
			else
			{
				Todo[] collection = new Todo[]
				{
					new Todo("hang out in tiger cage", "and survive", true),
					new Todo("unload Walmart truck", "keep steaks for dinner", false),
					new Todo("yell at staff", "maybe fire someone", false),
					new Todo("say no to drugs", "unless it's a drinking day", false),
					new Todo("listen to some tunes", "https://youtu.be/kTmZnQOfAF8", true)
				};
				list.AddRange(collection);
			}
			List<Todo> list2 = new List<Todo>();
			foreach (Todo todo in list)
			{
				if (!todo.Done)
				{
					list2.Add(todo);
				}
			}
			Note = list2[0].Note;
			return Note;

		}

		static byte[] Decode_Hash(String Password, String Note, String Step, String Desc)
		{
			HashAlgorithm hashAlgorithm = SHA256.Create();
			byte[] bytes = Encoding.ASCII.GetBytes(Password + Note + Step + Desc);
			byte[] first = hashAlgorithm.ComputeHash(bytes);
			byte[] second = new byte[]
			{
					50,
					148,
					76,
					233,
					110,
					199,
					228,
					72,
					114,
					227,
					78,
					138,
					93,
					189,
					189,
					147,
					159,
					70,
					66,
					223,
					123,
					137,
					44,
					73,
					101,
					235,
					129,
					16,
					181,
					139,
					104,
					56
			};
			return first;

		}


		public static string Decode_Pass(byte[] e)
		{
			string text = "";
			foreach (byte b in e)
			{
				text += Convert.ToChar((int)(b ^ 83)).ToString();
			}
			return text;
		}

	}
}
