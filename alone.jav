import javax.swing.*;
import java.awt.*;
import java.awt.geom.Line2D;
import java.util.Timer;
import java.util.TimerTask;

public class GraphAnimation extends JPanel {
    private float a = 1;
    
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;
        
        g2.setColor(Color.WHITE);
        g2.fillRect(0, 0, getWidth(), getHeight());
        
        g2.setColor(Color.BLACK);
        for (int i = 0; i < getWidth(); ++i) {
            float x = (i - getWidth() / 2) * (2.0f * (float) Math.sqrt(33) / getWidth());
            float y = (float) Math.pow(Math.abs(x), 2.0 / 3.0) + 0.8f * (float) Math.sqrt(33 - x * x) * (float) Math.sin(0.01f * a * Math.PI * x);
            int screenY = getHeight() / 2 - (int) (y * 20);
            g2.draw(new Line2D.Float(i, screenY, i, screenY));
        }
    }
    
    public static void main(String[] args) {
        JFrame frame = new JFrame("Graph Animation");
        GraphAnimation graph = new GraphAnimation();
        frame.add(graph);
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        
        Timer timer = new Timer();
        timer.scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                graph.a += 1;
                graph.repaint();
            }
        }, 0, 20);
    }
}
