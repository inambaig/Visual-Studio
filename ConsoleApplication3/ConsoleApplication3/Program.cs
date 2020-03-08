using System;

// include a class

class Letter
{
    public Letter()

    { }

    public string Recipin_Name { get; set; }
    public string Date { get; set; }
    public Letter(string Name, string Mailed)
    {
        Recipin_Name = Name;
        Date = Mailed;
    }
    public override string ToString()
    {
        return GetType().ToString() + " " + " Recipient Name : " + Recipin_Name + " Date of Mailing : " + Date;
    }
}

class CertifiedLetter : Letter
{
    public int TrackingNos { get; set; }
    public CertifiedLetter(string Name, string date, int track): base(Name, date)
    {
        TrackingNos = track;
    }

    public override string ToString()
    {
        return GetType().ToString() + " Recipient Name : " + Recipin_Name + " Date Mailed : " + Date + " " + " Tracking of the Number : " + TrackingNos;
    }
}

// main function

public class Letterdemo
{

    public static void Main()
    {
        CertifiedLetter Certi = new CertifiedLetter("Mr. XYZ", "Nov,18,2018", 08008);
        Console.WriteLine(Certi);
        Letter letter = new Letter("ABC", "Nov 12,2018");
        Console.WriteLine(letter);
    }

}

