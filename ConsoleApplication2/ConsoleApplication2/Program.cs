using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class SalesTaxDemo
    {
        int count = 10;
        Sale[] sale;

        public SalesTaxDemo()
        {
            sale = new Sale[count];
            for (int i = 0; i < count; i++)
            {
                sale[i] = new Sale();
            }
        }

        public void getSaleInfo()
        {
            for (int i = 0; i < count; i++)
            {
                int x = i + 1;
                Console.Write("Enter Inventory Number # " + x + " >> ");
                String invNum = Console.ReadLine();
                Console.Write("Enter Amount of sale # " + x + " >> ");
                int Amount = Convert.ToInt32(Console.ReadLine());
                sale[i].InventoryNumber = invNum;
                sale[i].Amount = Amount;
            }
        }

        public void showSaleInfo()
        {

            for (int i = 0; i < count; i++)
            {
                int x = i + 1;
                Console.Write("Sale # " + x);
                sale[i].displaySaleInfo();
            }
            Console.ReadKey();
        }

        static void Main()
        {
            SalesTaxDemo std = new SalesTaxDemo();
            std.getSaleInfo();
            std.showSaleInfo();
        }
    }

    class Sale
    {
        private String inventoryNumber;
        private double tax;
        private int amount;

        public Sale()
        {
            tax = 0;
        }

        public string InventoryNumber
        {
            get
            {
                return this.inventoryNumber;
            }
            set
            {
                this.inventoryNumber = value;
            }
        }

        public int Amount
        {
            get
            {
                return this.amount;
            }
            set
            {
                this.amount = value;
            }
        }
        public double Tax
        {
            get
            {
                return this.tax;
            }
            set
            {
                this.tax = value;
            }
        }
        private void CalculateTax()
        {
            double t1 = 0, a = 0, t2 = 0;
            if (Amount <= 100)
                Tax = Amount * 0.08;
            else
            {
                a = Amount - 100;
                t1 = 100 * 0.08;
                t2 = a * 0.06;
                Tax = t1 + t2;
            }
        }

        public void displaySaleInfo()
        {
            CalculateTax();
            Console.Write(" Amount: " + InventoryNumber);
            Console.Write(" Sale $" + this.Amount);
            Console.WriteLine("\n\tTax is $" + this.Tax);
        }

    }

}
