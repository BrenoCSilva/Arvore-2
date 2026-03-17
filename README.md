           <datasources>
                <datasource jndi-name="java:jboss/datasources/ExampleDS" pool-name="ExampleDS" enabled="true" use-java-context="true" statistics-enabled="${wildfly.datasources.statistics-enabled:${wildfly.statistics-enabled:false}}">
                    <connection-url>jdbc:h2:mem:test;DB_CLOSE_DELAY=-1;DB_CLOSE_ON_EXIT=FALSE</connection-url>
                    <driver>h2</driver>
                    <security>
                        <user-name>sa</user-name>
                        <password>sa</password>
                    </security>
                </datasource>
                
                <datasource jndi-name="java:jboss/datasources/JavaHostelDS" pool-name="JavaHostelDS" enabled="true" use-java-context="true">
            		<connection-url>jdbc:mysql://localhost:3306/javahostel?useSSL=false&amp;serverTimezone=UTC</connection-url>
            		<driver>mysql</driver>
            		<security>
                		<user-name>dwws</user-name>
                		<password>brenocosta3906</password>
            		</security>
        		</datasource>
        		
                <drivers>
                    <driver name="h2" module="com.h2database.h2">
                        <xa-datasource-class>org.h2.jdbcx.JdbcDataSource</xa-datasource-class>
                    </driver>
                    <driver name="mysql" module="com.mysql">
        				<driver-class>com.mysql.cj.jdbc.Driver</driver-class>
    				</driver>
                </drivers>
            </datasources>





pastas para o module.xml e o mysql-connector-j-9.6.0.zip (extrai e pega o .jar dentro e joga para fora):  wildfly.../modules/system/layers/base/com/mysql/main
