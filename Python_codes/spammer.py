from selenium import webdriver
import time
from selenium.webdriver.common.action_chains import ActionChains
driver=webdriver.Firefox(executable_path="C://selenium/geckodriver.exe")
for i in range(5):
    driver.get("https://flipkart.com")
    element = driver.find_element_by_class_name("_2IX_2-")
    element.send_keys("9390016262")

    element = driver.find_element_by_link_text("Forgot?")
    element.click()
    time.sleep(5)

'''
element=driver.find_element_by_tag_name("button")
action = ActionChains(driver).click(on_element = element).perform()'''



