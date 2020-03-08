using System;

public class SalesTaxDemo
{

    public static void Main()
    {
        int time = 10; 
        Sale[] sale = new Sale[10]; 
        for (int i = 0; i < 10; i++) sale[i] = new Sale();
        for (int i = 0; i < time; i++)
        {
            Console.Write("Enter inventory number #{0} >> ", (i + 1));
            sale[i].InventoryNumber = Console.ReadLine(); 
            Console.Write("Enter amount of sale >> ");
            sale[i].Amount = Convert.ToDouble(Console.ReadLine());
        }
        for (int i = 0; i < time; i++)
        { 
            Console.WriteLine("Sale # {0} Amount: {1} Sale ${2} Tax is ${3}", (i + 1), sale[i].InventoryNumber, String.Format("{0:n}", sale[i].Amount), String.Format("{0:n}", sale[i].Tax));
        }
    }
}

class Sale
{
    private string inventoryNumber;
    public string InventoryNumber
    {
        set
        {
            this.inventoryNumber = value;
        }
        get
        {
            return this.inventoryNumber;
        }
    }
    private double amount;
    public double Amount
    {
        set
        {
            amount = value;
        }
        get
        {
            return amount;
        }
    }
    private double tax;
    public double Tax
    {
        get
        {
            CalculateTax();
            return tax;
        }
    }
   
    private void CalculateTax()
    {
        if (amount > 100.0)
        {
            tax = 0.08 * 100 + 0.06 * (amount - 100.0);
        }
        else
        {
            tax = 0.08 * amount;
        }
    }
}