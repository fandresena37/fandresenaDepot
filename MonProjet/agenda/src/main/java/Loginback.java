

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

/**
 * Servlet implementation class Loginback
 */
public class Loginback extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Loginback() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		PrintWriter p = response.getWriter();
		String user = request.getParameter("user");
		String pass = request.getParameter("pass");
		int act = 0;
		try{// TODO Auto-generated method stub
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/agenda?characterEncoding=UTF-8","fandresena","Azerty123!");
			Statement st = con.createStatement();
			ResultSet res = st.executeQuery("select * from login");
			while(res.next()) {
				String userDB = res.getString(1);
				String passDB = res.getString(2);
				if(userDB.equals(user) && passDB.equals(pass)) {
					act = 1;
					break;
				}
			}
			if(act == 1) {
				FileWriter w1 = new FileWriter("login.txt",false);
				 try (FileWriter w = new FileWriter("login.txt", true)) {
	                w.write(String.format("%s",user));
	            } catch (IOException e) {
	                e.printStackTrace();
	            }
				response.sendRedirect("http://localhost:8080/agenda/accueilJSP.jsp");
			}
			else {
				response.sendRedirect("http://localhost:8080/agenda/login.html");
			}
			}
			catch(Exception e) {
				p.println("<p>tsy mety e </p>");
				p.println(e.getMessage());
			}
	}

}
