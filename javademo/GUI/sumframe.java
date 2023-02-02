import javax.swing.*;
import java.awt.*;
import java.awt.event.*;



class sumframe extends JFrame{
           private JLabel lb1,lb2,lb3;
           private JTextField txt1,txt2,txt3;
           private JButton b;
           private JScrollBar s;

public sumframe()
{
    lb1=new JLabel("num1");
    ImageIcon icona = new ImageIcon("/home/ajmal/Desktop/code.png");
    lb2 = new JLabel("num2",icona,JLabel.LEFT);

   icona.setDescription("ktu");
   icona.getIconHeight();
   icona.getIconWidth();
 s=new JScrollBar();
    lb3 = new JLabel("result");
    
    txt1= new JTextField(30);
    
    txt2= new JTextField(30);
    
    txt3= new JTextField(30);
    
    b=new JButton("Add");
    
    setLayout(new FlowLayout());
    add(lb1);
    add(txt1);
    
    add(s);
s.add(lb2);    
    add(txt2);
    add(lb3);
    add(txt3);
   
    add(b);
    setSize(3000,3000);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
   s.setUnitIncrement(1);
    
    setTitle("sumframe");
    setVisible(true);
    b.addActionListener(new add());
  
    }
  class add implements ActionListener{
    
    public void actionPerformed(ActionEvent e){
              String str=txt1.getText();
              String str1=txt2.getText();
              
              int n1= Integer.parseInt(str);
                int n2 = Integer.parseInt(str1);
                int result=n1+n2;
                String result1=Integer.toString(result);
                txt3.setText(result1);
    }
}

        }
