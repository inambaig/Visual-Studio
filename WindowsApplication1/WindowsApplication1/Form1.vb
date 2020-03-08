Public Class Form1

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        ListBox1.Items.Clear()
        Dim incrementer As Integer = 1
        Dim Str As String = ""
        Str = "n" & vbTab & "n^2" & vbTab & "n^3"
        ListBox1.Items.Add(Str)
        Do While incrementer <= TextBox1.Text
            Str = incrementer & vbTab & incrementer ^ 2 & vbTab & incrementer ^ 3
            ListBox1.Items.Add(Str)
            incrementer += 1 ' increment student counter
        Loop
    End Sub
End Class
