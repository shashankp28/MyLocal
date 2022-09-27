from typing import Optional
from pydantic import BaseModel
from user_management.models.user import User


class Token(BaseModel):
    access_token: str
    token_type: str


class TokenData(BaseModel):
    emailId: Optional[str] = None


class UserInDB(User):
    password: str
    isActive: bool
