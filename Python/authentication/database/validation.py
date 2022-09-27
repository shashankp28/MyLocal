from user_management.db_config import conn
from authentication.models.validation import UserInDB


def get_user(emailId: str) -> dict:
    if findRecordCount(emailId=emailId) != 0:
        return UserInDB(**conn.userManagement.find_one({"emailId": emailId}))
    else:
        return False


def findRecordCount(emailId: str) -> int:
    return conn.userManagement.count({"emailId": emailId})
