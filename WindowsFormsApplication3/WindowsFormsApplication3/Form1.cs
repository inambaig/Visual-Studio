using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication3
{
    public partial class Form1 : Form
    {
        Stack<string> s = new Stack<string>();
        List<char> li = new List<char>();
        List<string> nonContainer = new List<string>();
        string filename = "";
        public Form1()
        {
            InitializeComponent();
            nonContainer.Add("img");
            nonContainer.Add("hr");
            nonContainer.Add("br");
        }

        bool fillStack()
        {
            Boolean isBalanced = true;
            for (int i = 0; i < li.Count; i++) 
            {
                if (li[i] == '<')
                {
                    if (li[i + 1] == '/')
                    {
                        string tempString = "";
                        for (int j = i + 2; true; j++)
                        {
                            if (li[j] == '>' || li[j] == ' ')
                            {
                                if (!(nonContainer.Contains(tempString)))
                                {
                                    if (!(s.Peek().ToLower().Equals(tempString.ToLower())))
                                    {
                                        isBalanced = false;
                                        s.Pop();
                                    }
                                    s.Pop();
                                    richTextBox1.Text += "Found closing tag: </" + tempString + ">\n";
                                }
                                else
                                {

                                    richTextBox1.Text += "Found a non-container tag: </" + tempString + ">\n";
                                }
                                break;
                            }
                            tempString += li[j];
                        }
                    }
                    else
                    {
                        string tempString = "";
                        for (int j = i+1; true; j++)
                        {
                            if (li[j] == '>' || li[j] == ' ')
                            {
                                if (!(nonContainer.Contains(tempString)))
                                {
                                    s.Push(tempString);
                                    richTextBox1.Text += "Found opening tag: <" + tempString + ">\n";
                                }
                                else
                                {
                                    richTextBox1.Text += "Found non-container tag: <" + tempString + ">\n";
                                }
                                break;
                            }
                            tempString += li[j];
                        }
                    }
                    
                }
            }
            return isBalanced;
        }

        private void loadFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.ShowDialog();
            openFileDialog1.InitialDirectory = @"C:\";
            openFileDialog1.RestoreDirectory = true;
            openFileDialog1.Title = "Browse HTML Files";
            openFileDialog1.DefaultExt = "html";
            openFileDialog1.Filter = "html files (*.html)|*.html|All files (*.*)|*.*";
            openFileDialog1.FilterIndex = 2;
            openFileDialog1.CheckFileExists = true;
            openFileDialog1.CheckPathExists = true;
            filename = openFileDialog1.FileName;
            StreamReader reader = new StreamReader(filename);
            do
            {
                li.Add((char)reader.Read());
            } while (!reader.EndOfStream);
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void checkTagsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            bool res = fillStack();
            string []name = filename.Split('\\');
            if (res)
                label1.Text = name[name.Length - 1] + " has balanced tags";
            else
                label1.Text = name[name.Length - 1] + " has unbalanced tags";
        }
    }
}
